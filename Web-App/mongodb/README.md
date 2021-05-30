# mongodb-study

## 목차
<p>

[0. MongoDB란?](#0-MongoDB란?)
</p>
<p>

[1. 설치 방법](#1-설치-방법)<br>
&nbsp; &nbsp; [1.1. 윈도우](#11-윈도우)<br>
&nbsp; &nbsp; [1.2. 리눅스](#12-리눅스)
</p>

## 0. MongoDB란?

## 1. 설치 방법
### 1.1. 윈도우
<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/1.png" alt="커뮤니티 버전 MongoDB 설치">
    <div align="center"><figcation>[커뮤니티 버전 MongoDB 설치]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/2.png" alt="MongoDB 버전 확인">
    <div align="center"><figcation>[MongoDB 버전 확인 - 2021.05 현재 4.4.5임]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/3.png" alt="모든 기능이 포함된 Complete로 설치">
    <div align="center"><figcation>[모든 기능이 포함된 Complete로 설치]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/4.png" alt="네트워크 버전으로 설치">
    <div align="center"><figcation>[네트워크 버전으로 설치]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/5.png" alt="MongoDB GUI 툴킷인 Compass">
    <div align="center"><figcation>[MongoDB GUI 툴킷인 Compass 필요 시 설치]</figcation></div>
  </figure>
</div></p>


<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/6.png" alt="환경 변수 설정">
    <div align="center"><figcation>[환경 변수 설정]</figcation></div>
  </figure>
</div></p>

<p>

설치 경로를 변경하지 않았다면 `C:\Program Files\MongoDB\Server\4.4\bin`에 MongoDB 실행파일이 설치된다. 해당 경로를 시스템 변수 Path에 추가해준다.
</p>

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/1. 윈도우/7.png" alt="실행 확인">
    <div align="center"><figcation>[실행 확인]</figcation></div>
  </figure>
</div></p>

### 1.2. 리눅스
<p>우분투 20.04에 MongoDB를 설치하는 방법에 대해 다룬다.</p>

<p>

1. 공개 키 가져오기
</p>
<p>먼저 패키지 관리 시스템에서 사용할 공개키를 가져온다. 다음 명령어를 터미널에 입력한다.</p>

```
sudo apt-get update
```
```
sudo apt-get install gnupg
```
```
sudo wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | sudo apt-key add -
```

<p>

2. list 파일 생성</p>
<p>MongoDB를 위한 list파일을 생성해 줄 차례입니다. 이 방법은 ubuntu 버전에 따라 다를 수 있으며 ubuntu 20.04 focal 버전에 맞춰 작성되었으므로 주의한다.</p>

다음 명령어를 터미널에 입력해 list 파일을 생성한다.
```
echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.4.list
```

<p>

3. MOngoDB 패키지 설치</p>

```
sudo apt-get update
```
```
sudo apt-get install -y mongodb-org
```

<p>

4. MongoDB 시작</p>

```
sudo service mongod start
sudo service mongod status
```

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/2. 리눅스/1.png" alt="MongoDB 시작">
    <div align="center"><figcation>[MongoDB 시작]</figcation></div>
  </figure>
</div></p>

이후 다음 명령어를 통해 MongoDB에 접속, 작업을 수행한다.
```
Mongo
```

<p><div align="center">
  <figure>
    <img src="./resources/1. 설치 방법/2. 리눅스/2.png" alt="MongoDB 접속">
    <div align="center"><figcation>[MongoDB 접속]</figcation></div>
  </figure>
</div></p>

## 2. 기본 사용법
### 2.1. 데이터베이스 생성
<p>

`use [DB 명]`으로 원하는 이름의 DB를 생성할 수 있다.</p>

### 2.2. 컬렉션 생성
<p>

`use [원하는 DB 명]`으로 switch한 후, `db.[원하는 컬렉션 명].insert({...})`과 같이 컬렉션을 생성할 수 있다.</p>

터미널<br>
```
show dbs
use testdb
show tables
db.test_collection.insert({
    "name": "name 1"
    "sex": "male"
    "age": "22"
})
show tables
```