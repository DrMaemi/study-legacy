# Docker
Go언어로 작성된 리눅스 컨테이너 기반으로하는 오픈소스 가상화 플랫폼

<br>

## 목차
- [설치](https://github.com/DrMaemi/Study/blob/master/Dev-Ops/Docker/INSTALL.md)
- [삭제](https://github.com/DrMaemi/Study/blob/master/Dev-Ops/Docker/DELETE.md)

<br>

### 컨테이너 실행과 종료
- 컨테이너 생성: `docker container create`<br>
- 컨테이너 목록 확인: `docker container ps`<br>

<br>

### 컨테이너로 구성한 서비스 실행
터미널
```
mkdir -p /usr/share/nginx/html
echo "Web Server running: YES" > /usr/share/nginx/html/index.html
docker run -d -p 80:80 --name=MyWebServer -v /usr/share/nginx/html/:/usr/share/nginx/html nginx
curl http://localhost:80
```
<p>

결과
```
Web Server running: YES
```
</p>

<p>

터미널
```
docker stop MyWebServer
docker commit -a "drmaemi" MyWebServer nginxweb
docker rm -f MyWebServer
docker run -d -p 80:80 -v /usr/share/nginx/html/:/usr/share/nginx/html nginxweb
curl http://localhost/
```
</p>

<p>

결과
```
Web Server running: YES
```
</p>

<br>

### 도커 프로세스, 이미지 전부 삭제
```bash
docker rm -f $(docker ps -aq)
docker rmi -f $(docker images -aq)
```
<br>

### 도커 이미지 생성
```bash
docker build -t [원하는 이미지 이름] [dockerfile 경로]
```
<p>

예시
```bash
docker build -t test/vol .
```
</p>

<br>

### 도커 이미지를 프로세스로 실행
```
docker run -it --name [원하는 프로세스 이름] [실행시키고자 하는 이미지 이름] [실행 후 원하는 커맨드]
```

<p>

예시
```
docker run -it --name c2 test/vol /bin/bash
```
</p>

<br>

### 구동 중인 도커 이미지 저장
```bash
# terminal 1
docker run -it <image name>

# update docker image state
apt-get update
apt-get install vim-tiny
```
```bash
# terminal 2
docker ps
docker commit <docker img id> <name to save>
```

<br>

### 도커 이미지명 또는 태그명 변경
```bash
docker image tag <기존 이미지명>:<기존 태그명> <새 이미지명>:<새 태그명>
```