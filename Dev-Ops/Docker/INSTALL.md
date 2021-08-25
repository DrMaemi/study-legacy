# Docker 설치
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
$ sudo usermod -aG docker ${USER}
$ sudo reboot
```
```
$ docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
```
</p>


<p>

Docker를 처음 설치하면 `/var/lib/docker`에 관련 파일들이 위치하게 된다.
```
ExecStart=(중략) --data-root=/path/to/docker
```
위 설정의 경우 도커가 재설치되면 초기화됨. 이를 방지하기 위해
```
$ sudo su
# vi /etc/docker/daemon.json
{
    "data-root":"/path/to/docker"
}
```
저장 후
```
sudo systemctl daemon-reload
sudo systemctl restart docker
```
확인
```
$ cd /path/to/docker
$ sudo df -h --max-depth=1
xxxMB
```
</p>