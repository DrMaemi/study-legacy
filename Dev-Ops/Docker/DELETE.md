# 도커 삭제
<p>

설치된 도커 식별
```
dpkg -l | grep -i docker
```
</p>
<p>

패키지 삭제
```
sudo apt-get purge -y docker-engine docker docker.io docker-ce 
sudo apt-get autoremove -y --purge docker-engine docker docker.io docker-ce
```
위 명령은 호스트의 도커 이미지, 컨테이너, 볼륨 그리고 사용자 생성 구성 파일은 제거하지 않는다.
</p>
<p>

도커 운영 위치를 변경하기 위해 `/etc/docker/daemon.json` 파일에서 `data-root`를 기입하지 않았다면 다음과 같이 도커의 모든 이미지, 컨테이너 및 볼륨을 삭제할 수 있다.
```
sudo rm -rf /var/lib/docker /etc/docker
sudo rm /etc/apparmor.d/docker
sudo groupdel docker
sudo rm -rf /var/run/docker.sock
```
도커 운영 위치를 변경했다면 `data-root`에 기입됐던 경로의 폴더를 삭제해준다.
</p>