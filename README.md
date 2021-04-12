# TODO 앱을 직접 만들면서 배우는 node.js / express / bootstrap / jquery
[강좌 링크](https://swmaestro.goorm.io/learn/lecture/26936/todo-%EC%95%B1%EC%9D%84-%EC%A7%81%EC%A0%91-%EB%A7%8C%EB%93%A4%EB%A9%B4%EC%84%9C-%EB%B0%B0%EC%9A%B0%EB%8A%94-node-js-express-bootstrap-jquery)<br>

## 1. Node.js - Express 프로젝트 생성
[https://nodejs.org/en/](https://nodejs.org/en/) 에서 Node.js 다운로드<br>
npm도 같이 설치되도록 설치 마법사를 진행한다.<br><br>
프로젝트를 자동 생성하기 위해 express-generator를 전역 설치(-g 옵션)한다.

```powershell
npm install express-generator -g
```

express '프로젝트이름' 으로 Node.js - Express 프로젝트 생성

```powershell
express my-app
```

## 2. 웹 어플리케이션 구조 파악
<p>
  Express.js 웹 프레임워크를 이용하면 웹 어플리케이션을 만들기 위한 프로젝트 구조를 MVD(Model-View-Controller) 형태로 쉽게 생성 가능하다.
<p>

<p>

  [1. 프로젝트 생성](#1-nodejs---express-프로젝트-생성)과 같이 Express-Generator를 이용해서 프로젝트 골격 생성 가능하다.
</p>

<p>
  본 예제에서 만들 웹 어플리케이션의 기본 디렉토리 구조는 다음과 같다.
</p>

<p>
&nbsp; &nbsp; 1. public: 정적 리소스<br>
&nbsp; &nbsp; &nbsp; &nbsp; 1-1. images: 이미지<br>
&nbsp; &nbsp; &nbsp; &nbsp; 1-2. javascripts: 프론트엔드 자바스크립트<br>
&nbsp; &nbsp; &nbsp; &nbsp; 1-3. stylesheets: CSS<br>
&nbsp; &nbsp; 2. views: 템플릿(페이지)<br>
&nbsp; &nbsp; 3. routes: 요청을 처리하는 핸들러<br>
&nbsp; &nbsp; 4. node_modules: Node.js 확장 모듈<br>
&nbsp; &nbsp; 5. app.js: 메인 웹 서버
</p>

### app.js 분석
<p>
  필요한 모듈들(express, routing, http, path)을 가져온다.<br>
  이 모듈들은 Node.js에서 기본으로 제공하는 확장 모듈이다.
</p>

```javascript
var express = require('express')
  , routes = require('./routes')
  , todo = require('./routes/todo')
  , http = require('http')
  , path = require('path');
```
<p>
  이후 어플리케이션을 생성한다. 기본적으로 3000번 포트번호를 사용하여 동작하도록 지정한다.
</p>

```javascript
var app = express();	// 어플리케이션 생성
var port = 3000;		// 어플리케이션 포트
```

<p>
  이어서 어플리케이션의 각종 설정을 정의한다. 어떤 웹 서버 포트 번호를 사용할 것인지, 템플릿 폴더는 어디에 위치하는지, 어떤 템플릿 엔진을 사용할 것인지 정한다.<br>
  또한 파비콘을 사용하여 로그를 기록, 요청 본문을 파싱, 구식 브라우저의 http 메소드 지원, 라우팅 활성화 등을 수행한다.<br>
  마지막으로 public 디렉토리의 정적 리소스를 처리하도록 한다.
</p>

```javascript
app.configure(function(){
  app.set('port', port);                        // 웹 서버 포트
  app.set('views', __dirname + '/views');       // 템플릿
  app.set('view engine', 'ejs');                // 템플릿 엔진
  app.use(express.favicon());                   // 파비콘
  app.use(express.logger('dev'));               // 로그 기록
  app.use(express.bodyParser());                // 요청 본문 파싱
  app.use(express.methodOverride());            // 구식 브라우저 메소드 지원
  app.use(app.router);                          // 라우팅
  // 정적 리소스 처리
  app.use(require('stylus').middleware(__dirname + '/public'));
  app.use(express.static(path.join(__dirname, 'public')));
});
```

<p>
  한 가지 더 설정할 것은, 개발 버전임을 설정하여 에러가 발생했을 때 조금 더 명시적인 에러 메세지를 볼 수 있도록 한다.
</p>

```javascript
app.configure('development', function(){    // 개발 버전
  app.use(express.errorHandler());          // 에러 메세지
});
```

<p>
  라우팅 핸들러는 routes 디렉토리에서 정의할 것이므로 app.js 에서는 핸들러를 연결해주기만 한다.
</p>

```javascript
// 라우팅
app.get('/', routes.index);
app.get('/list', todo.list);
app.post('/add', todo.add);
app.post('/complete', todo.complete);
app.post('/del', todo.del);
```

<p>
  마지막으로 서버를 실행한다.
</p>

```javascript
// 서버 실행
http.createServer(app).listen(app.get('port'), function(){
  console.log("Express server listening on port " + app.get('port'));
});
```

## 3. 라우팅 정의
<p>
  라우팅 핸들러는 routes 디렉토리 하위에 정의한다.<br>
  이 예제에서는 index.js, todo.js 2가지 파일에 나누어 라우팅을 정의한다.
</p>

## index.js
<p>
  index.js는 홈페이지를 처리하기 위한 것이다. 홈페이지를 렌더링해주기만 하면 되고, views/index.ejs 
</p>