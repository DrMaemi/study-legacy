# Linux Study

<p>리눅스 시스템을 사용하면서 겪었던 불편을 해결할 수 있거나 유용했던 정보들.</p>

## 목차
<p>

- [초기 su 로그인 오류](#초기-su-로그인-오류)
- [tar, gz, zip 압축·해제](#tar-gz-zip-압축·해제)
- [screen](#screen)
- [tree](#tree)
- [화면 캡쳐 및 녹화](#화면-캡쳐-및-녹화)
- [호스트명 제어](#-호스트명-제어)
</p>

<br>

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

<br>

## tar, gz, zip 압축·해제
압축하고자 하는 파일들이 특정 폴더에 들어있을 때,

<p>

확장자 | 압축 | 해제
----- | ----- | -----
.tar | `tar -cvf <파일명.tar> <폴더명>` | `tar -xvf <파일명.tar>`
.tar.gz | `tar -zcvf <파일명.tar.gz> <폴더명>` | `tar -zxvf <파일명.tar.gz>`
zip | `zip <파일명.tar> <폴더명>` | `unzip <파일명.zip>`

</p>

<br>

## screen
터미널 환경에서 개발할 때 도움을 주는 Terminal multiplexer 종류의 소프트웨어

<br>

### 설치 및 .screenrc 설정
```
sudo apt install screen
```

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

### 사용법 - 진입 및 종료
<p>

`screen`: 일반적인 진입<br>
`screen -S <스크린 이름>`: 원하는 이름으로 스크린 생성 및 진입<br>
`screen -r <스크린 이름>`: 이미 실행된 Detached 스크린에 진입<br>
`screen -x <스크린 이름>`: 이미 실행된 Attached 스크린에 진입<br>
</p>
<p>

스크린을 종료하고 싶다면 스크린 진입 후 `exit`을 입력하면 된다.
</p>

<br>

### 스크린 진입 후 사용할 수 있는 단축키
<p>

스크린 진입 후 사용되는 단축키는 항상 `Ctrl` + `a` 입력 후 다른 키와의 조합으로 이루어진다. `Ctrl`과 `a`는 동시에 누르고, 쉬었다가 다음과 같은 추가 조합 키를 입력한다.</p>
<p>

`c`: 새 스크린 띄우기
`a`: 바로 이전 스크린으로 이동
`n`: 다음 스크린으로 이동
`p`: 이전 스크린으로 이동
`space`: 다음 스크린으로 이동
`backspace`: 이전 스크린으로 이동
`0`: 0번 스크린으로 이동
`1`: 1번 스크린으로 이동
...
`9`: 9번 스크린으로 이동
`d`: 스크린 탈출(해당 스크린은 계속 실행 중)

</p>

<br>

## tmux
터미널 환경에서 개발할 때 도움을 주는 Terminal multiplexer 종류의 소프트웨어

<br>

### 설치
```bash
sudo apt install tmux
```

<br>

### 실행
```
tmux
```

<br>

### tmux 용어집

용어 | 설명
-- | --
세션(session) | - tmux가 관리하는 가장 큰 실행 단위.<br>- tmux는 세션에 attach/detach 할 수 있다.<br>- tmux가 detach한 세션은 종료되지 않고 백그라운드에서 실행된다.
윈도우(window) | - 사용자가 보는 터미널 화면.<br>- 한 세션에는 여러 개의 윈도우가 탭처럼 존재.
팬(pane) | -하나의 윈도우엔 여러 개의 팬이 존재할 수 있다.<br>- 가로 혹은 세로로 화면을 분할하여 팬 생성 가능.

<br>

### 세션 명령어

명령 | 명령어 | 설명
-- | -- | --
생성 | `tmux new -s <세션 이름>` | 
이름 수정 | `Ctrl`+`b`+`$` | 
detach | `Ctrl`+`b`+`d` | 
attach | `tmux attach -t <세션 id 또는 세션 이름>` | 
세션 리스트 보기 | `tmux ls` | 
세션 종료 1 | `exit` | 해당 세션의 마지막 윈도우의 마지막 팬에서 실행
세션 종료 2 | `tmux kill-session -t <세션 이름>` | 해당 세션 밖에서 실행 가능

<br>

### 참조
[간략하게 보는 tmux 설치와 명령어 사용법, 경자 연구소, 2019년 1월 17일 수정, 2021년 11월 28일 접속, https://soft.plusblog.co.kr/19](https://soft.plusblog.co.kr/19)


<br>

## tree
<p>tree는 폴더 하위 구조를 계층적으로 표시해주는 유틸리티로, 전체 구조를 대략적으로 파악할 때 유용하다.</p>

### 사용법
<p>

depth 제한: -L 옵션
```bash
$ tree -L 2
```
</p>
<p>

directory만 표시: -d 옵션
```bash
$ tree -L 2 -d
```
</p>
<p>

no indentation + full path<br>
depth에 따른 들여쓰기 x: -i 옵션 추가<br>
파일 전체 경로 표시: -f 옵션 추가
```bash
$ tree -L 2 -d -fi
```
</p>
<p>

특정 폴더 이름 제외: -I 옵션 뒤 패턴 입력
```bash
$ tree -d -I "__pycache__.py|dataset|build"
```
</p>

<br>

## 화면 캡쳐 및 녹화
### 화면 캡쳐
<p>

&nbsp;|전체 화면|활성화 창|선택 영역
:-:|:-:|:-:|:-:
그림 파일로 자동 저장|`Print Screen`|`Alt` + `Print Screen`|`Shift` + `Print Screen`
클립 보드에 복사|`Ctrl` + `위 단축키`|`Ctrl` + `위 단축키`|`Ctrl` + `위 단축키`
</p>

<br>

### 화면 녹화
<p>

녹화 시작과 종료는 동일하게 `Ctrl` + `Alt` + `Shift` + `R` 단축키를 사용한다.
</p>
<p>녹화를 시작하면 화면 우측 상단에 레코딩 아이콘이 표시된다.</p>
<p>

저장 위치는 `~/Video` 폴더이고, 해당 폴더가 없다면 홈 디렉토리에 저장된다.</p>

<br>

### 화면 녹화 시간 변경 - dconf editor
<p>우분투를 설치하면 기본적으로 화면 녹화 시간이 30초로 제한되어 있다. 이를 변경하기 위해선 다음 과정을 수행해야 한다.</p>
<p>

1. dconf-editor 설치
```bash
sudo apt-get update -y
sudo apt-get install -y dconf-editor
```

2. dconf-editor에서 설정 변경
```bash
$ dconf-editor
```
위 명령어를 실행하면 editor 창이 열리는데, `org/gnome/settings-daemon/plugins/media-keys`로 이동해서 `max-screencast-length` 설정을 기본값 사용 해제, 사용자 설정 값 0으로 세팅한다.
</p>

<br>

## 호스트명 제어
<p>

터미널 창에서 볼 수 있는 `<user name>@<host name>:~$` 에서 `<host name>`과 관련된 명령들을 다음과 같이 사용할 수 있다.
</p>

명령어 | 역할
-- | --
`hostnamectl status` | 현재 호스트명 설정 조회
`hostnamectl set-hostname <host name>` | `<host name>`으로 호스트명 변경
`hostnamectl set -icon-name <icon name>` | `<icon name>`으로 호스트 아이콘명 변경
