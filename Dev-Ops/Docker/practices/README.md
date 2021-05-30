### 도커 빌드?
```
docker build -t test/env .
```

### 1. ENV와 ARG
- ENV

- ARG
<p>도커 이미지를 빌드할 때</p>

### 2. EXPOSE와 USER
<p>

컨테이너 어플리케이션의 포트를 지정하는 것은 도커 파일(dockerfile)과 무관함. 해당 어플리케이션의 config 파일을 수정하는 방식이기 때문. 도커 파일에서는 해당 어플의 포트를 **명시**하는 것일 뿐이다. 실제로 도커에 익숙한 엔지니어들이 자주 하는 착각이므로 주의한다.</p>

### 3. VOLUME
<p>도커 컨테이는 언제나 '죽을' 수 있는 프로세스. 따라서 컨테이너 프로세스가 죽더라도 내부 데이터를 보존할 수 있는 방법이 있어야 한다. 이 때 사용하는 것이 VOLUME 이다.</p>
<p>VOLUME 사용 시 가장 중요하면서 주의할 점은, 컨테이너가 죽고 다시 새로 생성되어 실행되면 VOLUME이 마운트된 경로가 겹쳐 어떤 컨테이너의 어떤 데이터인지 알아볼 수 없게 된다는 점이다. 따라서 컨테이너 run 시점에 호스트OS의 경로를 변경해야 한다.</p>

```
docker run -it -v /home/drmaemi/github-repos/docker-study/practices/3.volume/data/:/data test/vol /bin/bash
docker run -it -v /tmp/data/:/data/ test/vol /bin/bash
```

### 4. ONBUILD
<p>이미지를 생성하고 빌드할 때 도커 프로세스가 실행되는 형태가 아니라, ONBUILD 명령을 사용했던 이미지를 다른 도커 파일에서 FROM image 예약어를 사용하여 빌드했을 때 동작한다.</p>
<p></p>

### 5. HEALTHCHECK
<p>컨테이너의 프로세스 상태를 체크할 수 있다. 쿠버네티스를 활용할 때 진가를 발휘한다.</p>
<p>

다음과 같은 옵션을 가진다.
- --interval=DURATION : 헬스 체크 간격. 기본 값 30s
- --timeout=DURATION : 타임 아웃. 기본 값 30s
- --reties=N : 타임 아웃 시 최대 재시도 횟수. 기본 값 3
</p>

<p>

dockerfile 내용에 127.0.0.1로 연결을 시도하면, `docker ps`를 입력해서 컨테이너의 상태를 확인했을 때 healthy임을 확인할 수 있다.</p>
<p>반면 227.220.220.221로 연결을 시도하도록 dockerfile 내용을 수정하면 health: starting 상태가 오래 지속된다.</p>
<p>

`docker inpsect <컨테이너 id>`를 입력해서 자세한 로그를 확인할 수 있다.
</p>

### 6. Dockerfile 사용 권장 사항들
1. .dockerignore 파일 사용
<p>이미지 생성 작업에 불필요한 파일이나 디렉토리를 로드하지 않는다.(.gitignore 파일과 유사)</p>

2. 이미지는 가능한 적은 크기로 구성
<p>불필요한 패키지를 설치하지 않는다. ex)데이터베이스 이미지에 텍스트 편집기 등을 포함시키지 않는다.</p>

3. 한 컨테이너당 한 어플리케이션으로 구성
<p>어플리케이션을 여러 컨테이너로 분리하면 컨테이너를 확장하고 재사용하는 것이 훨씬 용이하다.</p>
<p>예를 들어, 일반적인 어플리케이션은 웹, DB, 인메모리-캐시(Redis 등)와 같이 세 개의 컨테이너로 구성할 수 있다.</p>

4. 이미지 레이어 수를 최소화
<p>

`RUN`, `COPY`, `ADD` 명령어는 새로운 레이어를 만든다.</p>

<p>

```
RUN apt-get -qq update
RUN apt-get -qq install some-package
```
를 다음과 같이 재구성한다.
```
RUN apt-get -qq update && apt-get -qq install some-package
```
</p>

### 7. Limit/Swap Memory
도커 프로세스들을 전부 중지시키고, health 디렉토리에서 다음과 같이 커맨드를 입력
```
docker run --name c1 -m 129m --memory-swap 129m -d smlinux/stress stress --vm 1 --vm-bytes 127m
```

```
docker run --name c1 -m 129m --memory-swap 129m -d smlinux/stress stress --vm 1 --vm-bytes 140m
```

<p>

이후에 `docker ps -a`를 입력해보면, 나중에 실행됐던 컨테이너가 종료됐음을 확인, `docker logs <컨테이너 id>`를 입력하면 리눅스의 stress 프로세스가 생성한 로그를 확인할 수 있다.
</p>

```
$ docker logs 4d11
stress: FAIL: ...
stress: WARN: ...
...
stress: FAIL: ...
```

<p>실제 리소스 점유율은 다음과 같이 확인할 수 있다.</p>

```
$ cd /sys/fs/cgroup/memory/docker/<구동중인 컨테이너 id>
$ cat memory.stat
```
혹은><br>
```
docker inpsect <구동중인 컨테이너 id>
```

<p>이런 메모리 swap과 limit을 사용하는 이유는, </p>

### 8. OOM Killer
<p>C언어에서 malloc() 등으로 메모리를 할당하더라도 바로 메모리 바인딩이 일어나지 않고 주소값만 반환한다. 실제로 데이터를 쓰기 시작하면 메모리가 바인딩된다. 이 경우 OOM(Out Of Memory) 문제가 발생하며, 리눅스의 OOM Killer가 </p>

### 9. Limit CPU

<p>

--cpuset-cpus
```
docker run --cpuset-cpus 1 --name c1 -d smlinux/stress:latest stress --cpu 1
```
</p>
<p>

--cpu-period=[value]<br>
... 등등의 옵션이 있는데 찾아보길
</p>

### 10. Limit Block IO
<p>

1. 사용하는 디바이스 및 파일시스템 확인
```
$ docker run -it --rm ubuntu
```
</p>
<p>

2. 컨테이너에서 --device-write-iops를 적용해서 write속도의 초당 quota를 제한해 IO write 발생시킴
- quota를 10으로 지정
```
$ docker run -it --rm --device-write-iops /dev/sda:10 ubuntu:latest /bin/bash
/# dd if=/dev/zero of=test.out bs=1M count=10 oflag=direct
```
</p>

### 11. cAdvisor
<p>컨테이너 리소스를 모니터링하기 위한 프로그램</p>

### 12. Limit Restarts
<p>

다음과 같은 옵션을 부여한다.<br>
restart={no | always | on-failure | unless-stoped}<br>
- no: 기본 값. 컨테이너가 명시적으로 실행될 때만 시작
- always: 어떤 종료코드로 종료했든 상관없이 docker 서비스가 시작되면 항상 해당 컨테이너 재시작
- on-failure: 0이 아닌 코드(비정상 종료)로 종료된 경우 해당 컨테이너 재시작, 횟수 지정 가능(on-failure:5)
- unless-stoped: docker 데몬 시작 시 
</p>
<p>always 옵션을 쓰는 경우 DB 상태 등에 따라 원치 않은 방향으로 컨테이너 동작할 수 있으니 주의한다.</p>
```
docker run -d --restart=always nginx
docker -
```