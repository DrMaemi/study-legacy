# Kubernetes: 운영 수준의 컨테이너 오케스트레이션

## 1. 설치
<p>쿠버네티스를 설치하기 위해선 다음과 같은 조건을 만족해야 한다.</p>
<p>

- 동작 환경
  - Ubuntu 16.04+
  - Debian 9+
  - CentOS 7
  - Red Hat Enterprise Linux (RHEL) 7
  - Fedora 25+
  - HypriotOS v1.0.1+
  - Flatcar Container Linux (tested with 2512.3.0)
</p>
<p>

- 시스템
  - RAM: 2GB 이상
  - CPU: 2코어 이상
  - 클러스터 간 Full Network Connectivity
</p>

<p>

- 보안 그룹(인바운드 규칙 오픈)
  - 마스터 노드
    - TCP 6783, UDP 6783/6784 (WeaveNet)
    - TCP 2379-2380 (etcd server client API / Used By kube-apiserver, etcd)
    - TCP 10250 (Kubelet API / Used By Self, Control plane)
    - TCP 10251 (kube-scheduler / Used By Self)
    - TCP 10252 (kube-controller-manager / Used By Self)
  - 워커 노드
    - TCP 6783, UDP 6783/6784 (WeaveNet)
    - TCP 10250 (Kubelet API / Used By Self, Control plane)
    - TCP 30000-32767 (NodePort Services / Used By All) 
</p>

<br>

### 1.1. 우분투
<p>

**실습 환경** - 본문을 작성할 때 AWS EC2 t2.medium 인스턴스 세 개를 만들어 하나는 마스터, 나머지 두 개는 워커 노드로 사용하였다.
</p>

<br>

- 마스터·워커 노드 공통

<p>

먼저 모든 인스턴스에 docker를 설치해준다.
```
sudo apt update
sudo apt install docker.io -y

# 데몬 설정
sudo su -
cat > /etc/docker/daemon.json <<EOF
{
  "exec-opts": ["native.cgroupdriver=systemd"],
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "100m"
  },
  "storage-driver": "overlay2"
}
EOF

sudo mkdir -p /etc/systemd/system/docker.service.d

# Docker 재시작.
sudo systemctl daemon-reload
sudo systemctl restart docker

sudo apt-get update
sudo apt-get upgrade

```
</p>
<p>

이후, `kubeadm`, `kubelet`, `kubectl` 설치
```
sudo apt-get install -y apt-transport-https curl
curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add -
cat <<EOF | sudo tee /etc/apt/sources.list.d/kubernetes.list
deb https://apt.kubernetes.io/ kubernetes-xenial main
EOF

sudo apt-get update
sudo apt-get install -y kubelet kubeadm kubectl

# 자동업데이트 방지
sudo apt-mark hold kubelet kubeadm kubectl

kubeadm version
kubelet --version
kubectl version

```
</p>
<p>

메모리 스왑 비활성화
```
sudo swapoff -a && sed -i '/swap/s/^/#/' /etc/fstab
```
</p>

<br>

- 마스터 노드

<p>

다음과 같이 kubeadm init 수행(1~5분 소요)
```
# ifconfig 등으로 Private IP 확인 후
sudo kubeadm init --pod-network-cidr=10.244.0.0/16 \
  --apiserver-advertise-address=<EC2 인스턴스 내부아이피>
```
</p>
<p>

`kubectl` 명령어를 실행하기 위해 다음과 같이 명령어 입력
```
mkdir -p $HOME/.kube
sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
sudo chown $(id -u):$(id -g) $HOME/.kube/config
```
</p>
<p>

마스터 - 워커 노드간 통신을 위한 CNI 네트워크 구성(Weave Net 설치)
```
kubectl apply -f "https://cloud.weave.works/k8s/net?k8s-version=$(kubectl version | base64 | tr -d '\n')"
```
</p>
<p>

설치 상태 확인
```
kubectl get nodes
kubectl get pods --all-namespaces
```
</p>
<p>

이제 워커 노드에서 마스터 노드에 접근하기 위해 필요한 토큰이 필요하다. 토큰은 `kubeadm init` 실행 시 발급된다. 발급된 토큰을 확인해본다.
```
kubeadm token list
```
</p>
<p>

디스커버리 토큰은 다음과 같이 확인 가능하다.
```
openssl x509 -pubkey -in /etc/kubernetes/pki/ca.crt | openssl rsa -pubin -outform der 2>/dev/null | openssl dgst -sha256 -hex | sed 's/^.* //'
```
</p>
<p>

토큰은 발행 후 24시간 뒤 만료되는데, 다음과 같이 새로 발행할 수 있다.
```
kubeadm token create
```
</p>
<p>

`kubectl` 명령어 자동완성 기능 사용
```
source /etc/bash_completion
source <(kubectl completion bash)
```
</p>

<br>

- 워커 노드
<p>

토큰을 이용해 마스터 노드에 접속
```
sudo kubeadm join <마스터노드 프라이빗 아이피>:6443 \
  --token <토큰> \
  --discovery-token-ca-cert-hash sha256:<디스커버리 토큰>
```
예시
```
sudo kubeadm join 172.31.6.154:6443 \
  --token huwr5s.wndv0ffwydgz6bej \
  --discovery-token-ca-cert-hash sha256:b6d236f0672581cdcae9af99bbfde0e57a9a3c6c6a1d64b52483f7a180412333
```
</p>

<br>

<p>

<div align="center">
  <figure>
      <img src="resources/k8s 환경 셋업.png" alt="k8s 환경 셋업" width="70%">
      <div align="center"><figcation>Kubernetes 실습 환경 구성 결과</figcation></div>
  </figure>
</div>
</p>

<br>

### 1.3. 삭제(검증 필요..)
```
sudo yum remove kubeadm kubectl kubelet kubernetes-cni kube*
```

<br><br>

## 2. Hello-World 배포
<p>

구글이 만들어 놓은 `Hello World` 이미지를 이용해 배포해본다.
```
# Master
kubectl create deployment kubernetes-bootcamp --image=gcr.io/google-samples/kubernetes-bootcamp:v1
```
</p>
<p>

다음 명령으로 배포 유무를 확인할 수 있다.
```
kubectl get deployments
```
</p>
<p>

포드 할당 확인. `10.244.X.X` 형태로 할당된다.
```
kubectl get pods -o wide
```
</p>
<p>

워커 노드에서 다음과 같이 명령을 실행하면 배포가 정상적으로 이루어졌는지 확인 가능
```
curl http://<할당받은 아이피>:8080
```
</p>