# Docker
Go언어로 작성된 리눅스 컨테이너 기반으로하는 오픈소스 가상화 플랫폼

<br>

## 목차
- [설치](https://github.com/DrMaemi/Study/blob/master/Dev-Ops/Docker/INSTALL.md)


### 컨테이너 실행과 종료
- 컨테이너 생성: `docker container create`<br>
- 컨테이너 목록 확인: `docker container ps`<br>

### 컨테이너로 구성한 서비스 실행
터미널<br>
```
mkdir -p /usr/share/nginx/html
echo "Web Server running: YES" > /usr/share/nginx/html/index.html
docker run -d -p 80:80 --name=MyWebServer -v /usr/share/nginx/html/:/usr/share/nginx/html nginx
curl http://localhost:80
```
결과<br>
```
Web Server running: YES
```

터미널<br>
```
docker stop MyWebServer
docker commit -a "drmaemi" MyWebServer nginxweb
docker rm -f MyWebServer
docker run -d -p 80:80 -v /usr/share/nginx/html/:/usr/share/nginx/html nginxweb
curl http://localhost/
```

결과<br>
```
Web Server running: YES
```

### 도커 프로세스, 이미지 전부 삭제
```
docker rm -f $(docker ps -aq)
docker rmi -f $(docker images -aq)
```

### 도커 이미지 생성
```
docker build -t [원하는 이미지 이름] [dockerfile 경로]
```
예시<br>
```
docker build -t test/vol .
```

### 도커 이미지를 프로세스로 실행
```
docker run -it --name [원하는 프로세스 이름] [실행시키고자 하는 이미지 이름] [실행 후 원하는 커맨드]
```
예시<br>
```
docker run -it --name c2 test/vol /bin/bash
```