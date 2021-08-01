# Linux Study

<p>리눅스 시스템을 사용하면서 겪었던 불편을 해결할 수 있거나 유용했던 정보들.</p>

## 목차
<p>

- [초기 su 로그인 오류](#초기-su-로그인-오류)
- [tar, gz, zip 압축·해제](#-tar-gz-zip-압축·해제)
- [screen](#-screen)
</p>

## 초기 su 로그인 오류
<p>

```
$ sudo passwd root
```
</p>
<p>

다른 유저의 비밀번호도 변경 가능하다.
```
$ sudo passwd user1
```
</p>

<br><br>

## tar, gz, zip 압축·해제
<p>

- tar
</p>
<p>

압축
```
tar -cvf <파일명.tar> <폴더명>
```
</p>
<p>

해제
```
tar -xvf <파일명.tar>
```
</p>
<br>
<p>

- tar.gz
</p>
<p>

압축
```
tar -zcvf <파일명.tar.gz> <폴더명>
```
</p>
<p>

해제
```
tar -zxvf <파일명.tar.gz>
```
</p>
<br>
<p>

- zip
</p>
<p>

압축
```
zip <파일명.tar> <폴더명>
```
</p>
<p>

해제
```
unzip <파일명.zip>
```
</p>

<br><br>

## screen
<p>

**설치**
```
sudo apt install screen
```
</p>

<br>

<p>

**유용한 환경설정**
</p>
<p>

`vi ~/.screenrc` 후에 다음 내용 작성
```
ck 5000
vbell off
defscrollback 10000
termcapinfo xterm* ti@:te@
startup_message off
hardstatus on
hardstatus alwayslastline
hardstatus string "%{.bW}%-w%{.rW}%n*%t%{-}%+w %= %c ${USER}@%H"
bindkey -k k1 select 0
bindkey -k k2 select 1
bindkey -k k3 select 2
```
</p>

<br>

<p>

**screen 생성**
```
screen -S <원하는 이름>
```
</p>