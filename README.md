# 한 눈에 끝내는 javascript & Node.js
<div align="right">

[강좌 링크](https://swmaestro.goorm.io/learn/lecture/26925/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-node-js)</div>

## 목차
<p>

[3. Node.js 소개](#3-Nodejs-소개)<br>
[&nbsp; &nbsp; 3-1. 개요](#3-1-개요)<br>
[&nbsp; &nbsp; 3-2. 이벤트 기반 비동기 방식](#3-2-이벤트-기반-비동기-방식)<br>
[&nbsp; &nbsp; 3-3. 그 외 특징들](#3-3-그-외-특징들)<br>
[&nbsp; &nbsp; 3-4. 아키텍처](#3-4-아키텍처)</p>
<p>

[4. Node.js 설치](#4-Nodejs-설치)</p>
<p>

[5. Node.js 간단한 실습](#5-Nodejs-간단한-실습)<br>
[&nbsp; &nbsp; 5-1. 웹 서버](#5-1-웹-서버)<br>
[&nbsp; &nbsp; 5-2. 파일 입출력](#5-2-파일-입출력)<br>
[&nbsp; &nbsp; 5-3. 비동기 이벤트](#5-3-비동기-이벤트)</p>
<p>

[6. Node.js 기본 모듈과 기초](#6-Nodejs-기본-모듈과-기초)<br>
[&nbsp; &nbsp; 6-1. 노드의 모듈화 개념](#6-1-노드의-모듈화-개념)<br>
[&nbsp; &nbsp; 6-2. 전역 객체](#6-2-전역-객체)<br>
[&nbsp; &nbsp; 6-3. 모듈의 종류](#6-3-모듈의-종류)<br>
[&nbsp; &nbsp; 6-4. 기본 모듈들 사용법](#6-4-기본-모듈들-사용법)</p>
<p>

[A. 추가 스터디](#A-추가-스터디)<br>
[async - await](#asnyc---await)</p>

---

## 3. Node.js 소개

### 3-1. 개요
<p>

Node.js는 **서버사이드 자바스크립트**이며 구글의 자바스크립트 엔진 V8을 기반으로 구성된 소프트웨어 시스템이다.</p>
<p>이벤트 기반 개발이 가능하고 Non-Blocking I/O를 지원하기 때문에 비동기식 프로그래밍이 가능하다. 이 때문에 I/O 부하가 심한 대규모 서비스를 개발하기 적합하다. 자바스크립트의 표준 라이브러리 프로젝트 CommonJS의 스펙을 따른다.</p>
<p>비동기 프로그래밍 모델은 최근 등장한 새로운 개념은 아니다. 대표적으로 Python의 Twisted, Perl의 Perl Object Environment, C의 libevent, Ruby의 EventMachine 등이 있다.</p>

### 3-2. 이벤트 기반 비동기 방식
<p>지금까지 대부분 어플리케이션은 Blocking I/O를 사용했고, 이 때문에 멀티 쓰레드를 사용했다. 멀티 쓰레드는 개발자 입장에서 직관적이고 멀티 태스킹을 위한 어쩔 수 없는 선택이지만 네트워크 입장에서 동시에 대규모 요청을 동시에 처리하는 데에는 부적절하다.</p>

#### Blocking I/O
<p>

**'하나의 프로세스가 어떤 자원을 사용하고자 할 때 그 자원을 다른 프로세스가 점유하고 있다면, 그 프로세스가 그 자원의 사용을 끝마칠 때까지 기다려야 한다는 것'**을 의미한다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 2]Blocking IO.png" alt="그림2">
  </figure>
</div>

#### 멀티 쓰레드
<p>CPU의 시분할 개념으로 요청을 처리한다는 개념이다. 여러 프로세스가 시간을 나누어 CPU를 사용하여 동작하게 함으로써 마치 CPU를 공유하여 사용하는 것과 같은 효과를 낸다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 3]멀티 쓰레드.png" alt="그림3">
  </figure>
</div>

<p>첫 번째 경우가 싱글 쓰레드로 요청을 처리할 때 모습이다. 먼저 들어온 요청이 가장 먼저 처리된다.</p>
<p>두, 세 번째 경우 멀티 쓰레드에 스케쥴링을 적용한 것이다. 특정 쓰레드가 일정 시간만 CPU를 사용할 수 있는데, 프로세스 B, C가 A보다 늦게 요청되었음에도 먼저 처리된다.</p>

#### 쓰레드로 인해 발생하는 문제
<p>멀티 쓰레딩의 근본적인 문제는 여러 쓰레드가 CPU라는 자원을 점유하기 위해 기다릴 수밖에 없고, 문맥 전환(Context switch) 비용이 발생한다는 점이다.</p>
<p>근본적 문제는 차치하더라도, 멀티 쓰레딩의 실질적 문제는 Blocking I/O 자체가 발생시키는 쓰레드 지연에 대한 문제이다. I/O 요청을 하고 응답이 올 때까지 아무것도 하지 않고 시간(자원)을 낭비하게 된다.</p>

#### 싱글 쓰레드와 이벤트 기반 비동기 I/O 처리
<p>노드는 이런 문제들을 해결하는 비동기 프로그래밍 모델을 제공한다.</p>
<p>싱글 쓰레드를 가진 노드는 I/O 작업이 시작되면 응답을 기다리지 않고 바로 다음 작업을 실행한다. 대신 I/O 작업이 종료되면 이벤트를 발생시키고, 이벤트는 해당 프로세스의 이벤트 큐에 등록된다. 노드로 개발된 프로세스는 이 이벤트를 감지하여 해당 이벤트 발생 시 수행해야 할 작업을 실행한다.</p>

#### 이벤트 루프(Event Loop)
<p>이벤트 루프는 작업을 요청하면서 그 작업이 완료됐을 때 어떤 작업을 진행할지에 대한 콜백 함수를 지정하여 해당 콜백 함수를 실행하는 동작 방식을 말한다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 4]이벤트 루프.png" alt="그림4">
  </figure>
</div>

<p>만약 클라이언트가 웹 서버에 HTTP 형식으로 요청하게 되면, 서버에서 실행중인 이벤트 루프가 이를 감지하고, 워커 쓰레드를 생성하여(? 노드는 싱글 쓰레드라 했는데, 쓰레드를 생성한다?) 알맞은 작업을 실행한다. 이 때 이벤트 루프는 해당 워커 쓰레드가 작업을 마친 뒤 결과와 함께 응답할 때까지 기다리지 않고 루프로 복귀하여 다른 요청을 기다린다.</p>
<p>

정리하자면 이벤트 루프는 **요청이 발생하면 그 요청에 대해 쓰레드 실행**만을 일으킨다. 해당 쓰레드가 작업을 마치면 미리 전달받은 콜백 함수를 실행하도록 이벤트 루프에게 응답하며 이벤트 루프는 이를 실행하고 클라이언트에게 결과를 응답한다.</p>

### 3-3. 그 외 특징들
- 자바스크립트 기반
- NPM을 통한 다양한 확장 모듈들
<p>NPM에 대해서는 7장에서 자세히 다룬다.</p>

### 3-4. 아키텍처

<div align="center">
  <figure>
    <img src="./git-resource/[그림 5]노드 아키텍처.png" alt="그림5">
  </figure>
</div>

<p>노드는 C/C++과 자바스크립트로 만들어졌다. C/C++은 레이어와 시스템 통합을 위해 사용되었다. V8 자바스크립트 엔진은 원래 구글 크롬이라는 웹 브라우저를 위해 만든 것이라 서버를 위해 설계된 것은 아닐 뿐더러 멀티 프로세스 모델에서 실행되는 것을 목표로 설계되었다. 노드에서 V8 엔진은 서버에서 동작할 수 있도록 변경되었다.</p>

<p>기술이 발전하며 초창기 아키텍처와 달리 노드 0.9버전부터 libev 종속성을 제거하며 libeio, libev가 libuv로 대체되었다.</p>

#### 노드 표준 라이브러리(Node standard library)
<p>V8을 이용해 특정 기능들을 수행할 수 있도록 도와주는 자바스크립트 기본 라이브러리다. 자바스크립트 언어로 작성되어 노드 바인딩과 연결된다.</p>

#### 노드 바인딩(Node bindings)
<p>C/C++로 구성된 시스템 바인딩 레이어다. C/C++로 작성된 라이브러리를 자바스크립트에서 사용할 수 있도록 결합하는 핵심 요소다.</p>
<p>소켓, http 등의 통신 기능이 제공되지만 DOM에 관한 기능은 제공하고 있지 않다. 소켓이나 http 등에 대한 노드 바인딩이 노드 표준 라이브러리와의 인터페이스 역할을 한다.</p>

#### V8 엔진
<p>V8 엔진은 구글에서 개발된 오픈소스 JIT 가상머신 형식의 자바스크립트 엔진이다. 구글 크롬 브라우저에 내장되어 있지만 독립적으로 실행 가능하다.</p>
<p>노드는 이 엔진을 이용해 자바스크립트로 개발된 노드 어플리케이션을 동작시킨다.</p>

#### 쓰레드 풀(Thread pool), libio
<p>쓰레드풀은 libio라는 비동기 I/O 라이브러리로 구성되어 있다. 즉, 파일 관련 작업(read, write, open, close, stat, unlink, fdatasync, mknod, readdir 등)을 수행한다. 이는 이벤트 기반 C언어용 I/O 라이브러리다.</p>
<p>노드에서의 비동기 I/O 작업들은 모두 이 라이브러리로 동작한다. 노드도 무조건 싱글 쓰레드만 사용하는 것은 아니고 내부적으로 멀티 쓰레드 풀을 사용하긴 한다.</p>

#### 이벤트 루프(Event Loop), libev
<p>이벤트 루프는 libev를 이용하여 구성된다.</p>

#### C-ares
<p>동시에 복수 DNS 쿼리를 비동기 처리하기 위한 C 라이브러리다.</p>

## 4. Node.js 설치
<p>

다음과 같은 세 가지 방법으로 Node.js를 설치할 수 있다.
- 소스코드 다운 및 빌드, 패스 설정(우분투, 맥)
- 패키지 매니저(우분투, 맥)
- 공식 인스톨러(윈도우, 맥)</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 6]노드 설치.png" alt="그림6">
  </figure>
</div>

<p>

**소스 코드 다운 및 빌드** 방법은 필요 라이브러리를 설치하는 것이 우선이다. 이후 소스 코드 다운, gcc를 이용해 컴파일 및 빌드하고 어디서든 노드 명령어를 이용할 수 있게 환경 변수 경로를 설정한다.</p>

<p>

**패키지 매니저** 방법은 `apt-get` 명령어를 이용해 쉽게 소프트웨어를 설치 및 관리할 수 있는데, 우분투에서 기본적으로 제공하는 소프트웨어 저장소에 노드가 없으므로 노드 설치와 관련된 정보를 가진 저장소를 추가하고 이를 이용해 설치하는 방식이다. 맥과 윈도우의 경우 써드파티에서 만든 소프트웨어 패키지 매니저가 있는데 이를 이용해 우분투와 유사하게 설치 가능하다.</p>

<p>

**공식 인스톨러** 방법은 노드 [공식 홈페이지](https://nodejs.org/ko/download/)에서 인스톨러를 다운받아 실행해 설치하는 방법이다. 이렇게 설치한 경우 노드의 여러 버전 관리가 불가능해 불편하다. 이미 노드를 설치했다면 깔끔히 삭제하기도 번거롭다. 이런 문제 때문에 인스톨러 대신 노드를 버전별 설치/관리할 수 있는 NVM(Node Version Manager)를 이용하는 것이 좋다.</p>

<p>노드에는 LTS 버전과 Current 버전이 있는데 차이는 다음과 같다.</p>

<p>

- **LTS 버전**
  - 장기적으로 지원이 제공되는 안정적 버전
  - 안정성과 보안성에 초점</p>
<p>

- **Current 버전**
  - 잦은 업데이트
  - 가장 최신 버전으로 불안정, 숨겨져 있는 버그 많음
  - 추가 기능 개발과 기존 API 기능 개선 우선</p>

#### REPL(Read Eval Print Loop)
<p>노드가 설치되면 터미널과 같은 커맨드 라인 입력 인터페이스를 통해 REPL을 사용할 수 있다.</p>
<p>REPL은 웹 브라우저의 자바스크립트 콘솔(F12를 눌러 이용 가능)과 유사하다. 하지만 HTML 페이지와 연결되지 않기 때문에 DOM이 존재하지 않는다.</p>
<p>REPL을 이용해 간단한 코드를 작성하여 실행해보거나 테스트해볼 수 있다.</p>

## 5. Node.js 간단한 실습
### 5-1. 웹 서버
<p>노드를 이용하면 다음과 같이 단 몇 줄만으로 웹 서버를 만들 수 있다.</p>

hellonode1.js<br>
```javascript
// hellonode1.js
var server = require('http');

server.createServer(function(req, res) {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end("Hello node.js !\n");
}).listen(3000, 'localhost');

console.log("Server is running at http://localhost:3000/');
```
서버 구동<br>
```
node hellonode1.js
```

### 5-2. 파일 입출력
hello.txt<br>
```
Hello !
```

main.js<br>
```javascript
var fs = require("fs");

fs.readFile('./hello.txt', encoding='utf-8', function(err, data) {
  if (err) throw err;
  console.log(data+" Node.js !");
});
```

### 5-3. 비동기 이벤트
<p>노드에서 비동기 이벤트를 생성하고 관리하도록 기능을 제공하는 events 모듈을 사용해본다.</p>

main.js<br>
```javascript
var EventEmitter = require('events').EventEmitter;
// 이벤트 객체 생성
var evt = new EventEmitter();

// 'helloNode'라는 이벤트가 발생하면
evt.on('helloNode', function(str) {
  // 해당 이벤트를 통해 전달된 인자를 입력받아 콘솔로 출력
  console.log("Hello! "+str);
});

// 자바스크립트 기본 메소드. 밀리 세컨드 단위로 특정 함수를 콜백으로 실행
setTimeout(function() {
  // 'helloNode' 이벤트 발생, 'Node.js' 문자열을 인자로 전달
  evt.emit('helloNode', 'Node.js');
}, 3000);
```

## 6. Node.js 기본 모듈과 기초
<p>노드에서 모듈이라는 개념은 노드로 개발한 어플리케이션을 이루는 기본 조각이라 할 수 있다.</p>
<p>일반적으로 노드로 개발된 어플리케이션은 객체 지향 개념이 아주 잘 녹아 있는 자바스크립트를 기반으로 하며, 파일과 1:1 맵핑이 되는 다양한 모듈로 구성된다.</p>

### 6-1. 노드의 모듈화 개념
<p>노드는 확장성을 위해 모듈 구조를 이용하여 어플리케이션을 구성하도록 한다. 모듈 단위로 구성된다는 것은 객체 지향 컨셉으로 어플리케이션이 구성된다는 것을 의미한다. 모듈화가 가능한 이유는 노드가 CommonJS 스펙을 대부분 준수하기 때문이다.</p>
<p>기본적으로 노드의 모듈은 자바스크립트 파일 하나와 1:1 맵핑되며 이러한 형태는 다음 장에서 설명할 NPM으로 할 수 있는 노드 확장 모듈의 개발을 편리하게 해준다.</p>

### 6-2. 전역 객체
<p>전역 객체는 어디에서나 사용할 수 있는 객체를 말한다. client 사이드 자바스크립트에서 window나 document와 같은 객체를 전역 객체라 말할 수 있다. 예를 들어 우리가 alert()이라는 함수를 사용할 때 단순히 alert('메세지')만 입력하더라도 사실 window라는 객체의 window.alert() 함수를 사용하는 것이다.</p>
<p>마찬가지로 서버 사이드에서 동작하는 노드의 경우 "global"이라는 전역 객체가 존재하는데, 우리가 앞으로 모듈을 불러올 때 사용할 require()를 비롯한 setTimeout(), console.log() 등을 포함하고 있다.</p>

```javascript
// 다음 두 개는 같은 기능을 수행하는 코드이다.
require('./module');
global.require('./module');
```

### 6-3. 모듈의 종류
<p>노드에서는 모듈의 종류를 크게 다음과 같은 기준으로 나눈다.</p>
<p>

- 노드 설치 시 기본적으로 설치되는 모듈: **기본 모듈** / **확장 모듈**
- 자바스크립트로 작성됐는지, C/C++등의 다른 언어로 작성 후 빌드됐는지: **일반 모듈** / **네이티브 모듈**
- 현재 어플리케이션만을 위해서 설치됐는지: **로컬 모듈** / **글로벌 모듈**
</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 7]모듈 종류.png" alt="그림7">
  </figure>
</div>

<p>모듈의 종류를 알고 있는 것이 개발에 큰 영향을 미치진 않지만 모듈을 로딩하고 체계적으로 NPM을 배포하기 위해서 각 모듈의 특징 정도는 알아두는 것이 좋다.</p>

#### 기본 모듈 / 확장 모듈
<p>기본 모듈은 파일 입출력, 이벤트 관리, HTTP 프로토콜 관리 등에 관한 내용으로 노드의 비동기 입출력 처리를 위한 기본적 기능들을 제공하는 모듈이다.</p>
<p>확장 모듈은 노드의 기능을 확장하기 위한 것으로 좀 더 쉬운 HTTP 서버 생성, 기본 파일 입출력에서 제공하지 않는 기능 추가 등 노드를 확장하고 더 편리하게 사용하기 위한 모듈이다.</p>
<p>확장 모듈은 나중에 소개할 Express와 같은 모듈들처럼 하나의 프레임워크로서 제공되기도 하며, mongodb를 사용하기 위한 mongoose, mongolian처럼 다른 기술을 쉽게 접목하여 사용할 수 있도록 도와준다.</p>

#### 일반 모듈 / 네이티브(기본) 모듈
<p>개발 방법에 따라 나눌 수 있는 종류다. 노드의 네이티브 모듈은 C/C++로 개발된 경우가 대부분이다.</p>
<p>확장 모듈 또한 네이티브 모듈로 개발할 수 있다. .node라는 확장자를 가졌으면 네이티브 모듈로 컴파일된 것이다.</p>
<p>일반 모듈은 노드의 모듈 인터페이스를 통해 간단히 자바스크립트로 개발된 모듈이다.</p>

#### 글로벌 모듈 / 로컬 모듈
<p>모듈을 설치할 때 해당 어플리케이션에서만 사용하기 위해 설치한 경우 로컬 모듈이다. 글로벌 모듈로 설치하려면 설치 시 옵션 -g 을 이용한다.</p>

#### 복합 모듈
<p>내부 모듈이나 데이터 파일, 템플릿, 테스트 코드 등을 포함하는 모듈을 말한다. 다양한 파일을 포함하기 때문에 모듈을 구성하는 단위가 폴더이며 내부에 폴더를 가질 수 있다.</p>
<p>require() 메소드가 이런 폴더 단위의 모듈을 인식하려면 index.js 파일이나 pakage.json 파일 중 하나가 반드시 있어야 한다.</p>

#### 모듈 식별자(상대적 식별자, 절대적 식별자, 최상위 레벨 식별자)
<p>노드의 모듈 이름으로는 확장자 없는 전체 경로를 사용한다. 앞서 설명한 것처럼 모듈은 파일과 일대일로 대응하기 때문에 .js나 .node라는 확장자를 가지지만 모듈을 불러들일 때는 파일 이름만 사용한다.</p>

#### 상대적 식별자
<p>현재 위치를 기준으로 상대 경로에 있는 모듈을 찾는 식별자이다. ./를 생략하면 상대 경로로 인식하지 않으니 주의한다.</p>

```javascript
require('./sample_module');
```

#### 절대적 식별자
<p>절대 경로에 있는 모듈을 찾는 식별자이다.</p>

```javascript
require('/usr/local/node_modules/sample_module/');
```

#### 최상위 레벨 식별자
<p>모듈 이름만을 입력하면 최상위 레벨 식별자로 인식하고 설치된 전체 확장 모듈과 기본 모듈 중 해당 모듈 이름을 검색하여 로드한다.</p>

```javascript
require('sample_module');
```

<p>

여기서 중요한 점은 sample_module이라는 **모듈 식별자를 찾는 순서**이다. 만약 해당 모듈이 기본 모듈에서 찾을 수 없는 모듈이라면 상위 디렉토리를 차례대로 탐색한다. 예를 들면 다음과 같은 순서로 탐색한다.</p>

```
/home/goorm/example_project/node_modules/sample_module.js
/home/goorm//node_modules/sample_module.js
/home/node_modules/sample_module.js
/node_modules/sample_module.js
```

#### require() 메소드와 module.exports
<p>모듈 개념에서 require() 메소드와 module.exports는 매우 중요하다.</p>
<p>client 사이드 자바스크립트와 비교해보자면, 웹 브라우저에서는 html의 script 태그로 필요한 자바스크립트를 연결하고 호출하게 되어있다.</p>

```html
<!DOCTYPE html>
<html>
  <body>
    <script type="text/javascript" src="goorm1.js"></script>
  </body>
</html>
```

<p>이렇게 html 스크립트를 통해 명시된 자바스크립트 파일들은 웹 브라우저에 의해 로딩되며 서로 참조하거나 호출할 수 있다. 하지만 노드는 html을 사용하지 않으므로 서로 다른 자바스크립트 파일들이 서로 참조하고 호출하는 방법이 필요하다.</p>
<p>

require() 메소드는 모듈 식별자인 module.exports를 이용해 모듈이 제공하는 함수나 객체 등을 반환한다. **불러온 모듈의 모든 의존성 모듈도 같이 로드한다.**</p>

<p>노드에서 하나의 자바스크립트 파일은 하나의 모듈이 될 수 있다. 이 때 자바스크립트 파일 내부의 함수나 변수를 module.exports에 할당하면 외부에서 접근 가능하다.</p>

### 6-4. 기본 모듈들 사용법

#### (1) 전역 객체: Global
#### (1)-(1) console
</p>

[API 문서](https://nodejs.org/api/console.html)</p>
<p>

- console.log(): 콘솔에 로그 메시지 출력
- console.time(label): 시간 측정 시작
- console.timeEnd(label): 시간 측정 종료
</p>

#### (1)-(2) process
<p>

[API 문서](https://nodejs.org/api/process.html)</p>
<p>process 객체는 자바스크립트에는 없는 Node.js만의 객체이다.</p>

<p>

**속성**</p>
<p>

- process.argv: 프로그램의 매개변수 정보
- process.env: 컴퓨터 환경과 관련된 정보
- process.version: Node.js의 버전
- process.versions: Node.js 프로세스에서 사용하는 모듈들의 버전
- process.arch: 프로세서의 아키텍처
- process.platform: 플랫폼 정보
</p>

<p>

**메소드**</p>
<p>

- process.exit(): 프로그램 종료
- process.memoryUsage(): 메모리 사용 정보
- process.uptime(): 현재 프로그램이 실행된 시간
</p>

예제<br>
```javascript
console.log("process env property: ", process.env);
console.log("uptime method: ", process.uptime());
```

#### (2) Exports 객체
<p>작성한 자바스크립트 파일을 모듈화시키고 외부에서 접근토록 만들어준다.</p>

calculator.js<br>
```javascript
exports.double = function(r) { return r*r; };
exports.plus = function(r) { return r+r; };
```
main.js<br>
```javascript
var calculator = require('./calculator');
console.log('double:', calculator.double(3));
console.log('plus:', calculator.plus(3));
```
결과<br>
```
> node main.js
double: 9
plus: 6 
```

#### (3) OS 모듈
<p>

[API 문서](https://nodejs.org/api/os.html)</p>
<p>실제 개발에서 많이 사용되는 모듈은 아니지만 운영체제와 시스템의 정보를 가져올 수 있는 모듈이다.</p>
<p>CPU, 메모리, 디스크 용량에 대한 정보를 확인할 때 사용한다.</p>
<p>


<p>

**주요 메소드**
- os.tmpdir(): 임시 저장 폴더 위치
- os.endianness(): CPU의 endianness(BE or LE)
- os.hostname(): 호스트(컴퓨터) 이름
- os.type(): 운영체제 이름
- os.platform(): 운영체제 플랫폼
- os.arch(): 운영체제 아키텍처
- os.release(): 운영체제 버전
- os.uptime(): 운영체제가 실행된 시간
- os.loadavg(): 로드 에버리지 정보를 담은 배열
- os.totalmem(): 시스템의 총 메모리
- os.freemem(): 시스템의 가용 메모리
- os.cpus(): CPU의 정보를 담은 객체. 세부 정보를 반환
- os.networkInterfaces(): 네트워크 인터페이스 정보를 담은 배열</p>

<p>

**OS 객체의 유일한 속성**
- os.EOL: 운영체제의 개행문자(\n과 같은)</p>

예제<br>
```javascript
var os = require('os');

console.log(os.tmpdir());
console.log(os.type());

var cpus = os.cpus();

for(var i = 0; i < cpus.length; i++) {
	console.log("CPU[" + (i+1) + "]");
	console.log("model: " + cpus[i].model);
	console.log("speed: " + cpus[i].speed);
}
```

## A. 추가 스터디
### asnyc - await
<p>async와 await는 자바스크립트의 비동기 처리 패턴 중 가장 최근에 나온 문법이다.</p>
<p>기존 비동기 처리 방식인 콜백 함수와 Promise의 단점을 보완하고 개발자가 읽기 좋은 코드를 작성할 수 있게 한다.</p> 

