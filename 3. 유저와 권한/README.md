# 유저와 권한
<p>다중 유저의 서버 환경에서 반드시 익혀야 할 리눅스 명령어들을 다룬다. 이는 보안과 밀접한 관계에 있고 매우 중요하다.</p>

<br><br>

## 목차
<p>

[1. 유저와 그룹](#1-유저와-그룹)<br>
&nbsp; &nbsp; [1.1. 생성](#11-생성)<br>
&nbsp; &nbsp; [1.2. 권한 부여](#12-권한-부여)<br>
&nbsp; &nbsp; [1.3. 조회](#13-조회)
</p>

<br><br>

## 1. 유저와 그룹
### 1.1. 생성
<p>

유저 생성<br>
```
$ sudo useradd user1
```
<br>

그룹 생성<br>
```
$ sudo addgroup soma
```
<br>

유저 패스워드 변경<br>
```
$ sudo passwd user1
```
<br>

유저 전환<br>
```
$ su user1
```
</p>

<br><br>

### 1.2. 권한 부여
<p>리눅스의 skicky bit와 관련 있다.</p>

```
$ sudo usermod -aG sudo user1
$ sudo usermod -aG soma user1
```

<br><br>

### 1.3. 조회
<p>

`useradd`를 통해 생성한 유저만 조회
```
$ grep /bin/bash /etc/passwd
$ grep /bin/bash /etc/passwd | cut -f1 -d:
```
<br>

그룹 조회
```
$ cat /etc/group
```
</p>

<br><br>

### 1.4. 삭제
<p>

유저 삭제<br>
```
sudo userdel user1
```
<br>

그룹 삭제<br>
```
sudo groupdel soma
```
</p>