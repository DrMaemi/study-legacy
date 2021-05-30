## Docker Network
### 개요
<p>본래 도커 컨테이너끼리 통신이 불가능하다. 컨테이너끼리 통신하기 위해서 docker0의 브릿지 네트워크를 두고 통신함(그림자료를 찾아봐야 할 듯)</p>


### iptables
<p>iptable은 리눅스에서 방화벽 역할을 수행하는 도구인데, 주로 패킷 필터링과 NAT 프로세싱을 처리한다.</p>

`$ docker run -d -p 8080:80 nginx`로 nginx 도커 컨테이너를 구동시켜보면, 이후 `$ iptables -t nat -L -v -n`으로 PREROUTING 룰과 DOCKER Chain에 관련 정책이 자동으로 생성됐음을 확인할 수 있다.

<p>근데 도커 컨테이너가 죽거나 재구동하게 되면 iptables에 관련 정책이 생성되지 않는 경우가 있다. 이런 경우를 대비해 직접 정책을 iptables에 기입하는 것이 좋다.</p>


### 컨테이너간 통신 인터페이스 확인
`$ brctl show`을 이용해 도커 컨테이너간 통신을 가능케하는 브릿지 네트워크의 유무를 확인할 수 있다.


## Docker Daemon
<p>도커 설정을 커스터마이징하고 싶을 때, /etc/docker/daemon.json 파일을 생성하고 json 형태로 설정을 할 수 있다.</p>
<p>해당 파일은 원래 없는 파일이므로 생성 후 설정한다.</p>
<p>

도커가 iptable을 사용하지 않도록 설정하기 위해 다음과 같이 작성한다.
```json
// /etc/docker/daemon.json
{
    "iptables": false
}
```
</p>

<p>

이후 `$ iptables -t nat -L DOCKER -n`으로 DOCKER Chain을 살펴보면, 포트포워딩하는 부분이 작성되지 않았음을 확인할 수 있다.
</p>
<p>

그러나 `curl localhost:8080`으로 여전히 도커 컨테이너의 nginx 웹에 접근할 수 있는데, 이는 docker-proxy가 백업용으로 iptables를 사용하지 못하더라도 포트포워딩이 될 수 있도록 하기 때문
</p>
<p>

`ps -ef | grep docker-proxy`로 관련 프로세스들을 `kill -9 <pid>`로 강제 종료시키면 도커 컨테이너의 웹 서비스에 접근하지 못한다.
</p>