# Docker 설치
## 기본
<p>

도커 설치
```
sudo apt update
sudo apt install docker.io -y
```
</p>
<p>

```
$ docker ps
Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get http://%2Fvar%2Frun%2Fdocker.sock/v1.24/containers/json: dial unix /var/run/docker.sock: connect: permission denied
```
</p>
<p>

위 문제를 해결하기 위해
```
$ sudo usermod -aG docker ${USER} && newgrp docker
```
```
$ docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
$ docker version
...
```
</p>

<br>

## NVIDIA 도커 설치
<p>도커 컨테이너는 호스트 OS와 격리되어 동작하기 때문에 GPU를 사용하기 위해서는 특별한 도커를 설치해야 한다. 그 특별한 도커는 NVIDIA 도커이다.</p>
<p>NVIDIA 도커는 호스트의 GPU 드라이버와 연동하는 드라이버를 제공하여 컨테이너가 동작할 수 있도록 한다.</p>
<p>

혹시 설치된 이전 버전이 있고 그것을 지우고 싶다면
```
docker volume ls -q -f driver=nvidia-docker | xargs -r -I{} -n1 docker ps -q -a -f volume={} | xargs -r docker rm -f
sudo apt-get purge -y nvidia-docker
```
</p>
<p>

설치
```
distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo apt-key add -
curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sudo tee /etc/apt/sources.list.d/nvidia-docker.list
sudo apt-get update && sudo apt-get install -y
```
</p>
<p>

도커 재구동
```
nvidia-container-toolkit sudo systemctl restart docker
```
</p>
<p>

설치 검증
```
# docker version 19.03 이상
docker run --gpus all nvidia/cuda:10.0-base nvidia-smi
# docker version 19.03 미만
docker run --runtime=nvidia nvidia/cuda:10.0-base nvidia-smi
```
</p>

<br>

## 도커 운영 위치 변경
<p>

Docker를 처음 설치하면 `/var/lib/docker`에 관련 파일들이 위치하게 된다.
```
ExecStart=(중략) --data-root=/path/to/docker
```
위 설정의 경우 도커가 재설치되면 초기화됨. 이를 방지하기 위해
```
$ sudo su
# vi /etc/docker/daemon.json
```
```json
/* daemon.json */
{
    "data-root":"/path/to/docker"
}
```
`/path/to/docker`에서 가장 앞에 `/`를 제거해도 **자동으로 `/`를 삽입한 경로로 인식하므로 주의**
</p>
<p>

저장 후
```
sudo systemctl daemon-reload
sudo systemctl restart docker
```
확인
```
$ cd /path/to/docker && ls
buildkit    image    overlay2  runtimes  tmp    volumes
containers  network  plugins   swarm     trust
```
</p>