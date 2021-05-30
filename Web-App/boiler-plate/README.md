# react-node boiler-plate

## 목차
<p>

[0. Node.js, Express.js 다운, 개발환경 구축](#0-Nodejs,-Expressjs-다운,-개발환경-구축)
</p>
<p>

[1. Hello World](#1-Hello-World)
</p>
<p>

[2. MongoDB 연동](#2-MongoDB-연동)<br>
&nbsp; &nbsp; [2.1. 클러스터 생성](#21-클러스터-생성)<br>
&nbsp; &nbsp; [2.2. 유저 생성](#22-유저-생성)<br>
&nbsp; &nbsp; [2.3. Node와 연동](#23-Node와-연동)<br>
&nbsp; &nbsp; [2.4. Mongoose 다운](#24-Mongoose-다운)<br>
&nbsp; &nbsp; [2.5. 환경변수 proces.env.NODE_ENV](#25-환경변수-procesenvNODE_ENV)
</p>


## 0. Node.js, Express.js 다운, 개발환경 구축
<p>

npm을 다운받고, `npm init`으로 node 개발환경을 구축한다. 다음 사항들만 기입하고 나머지는 default값을 사용했다.
```
'name': 'boiler-plate'
'description': 'react-node-practice with implementing boiler-plate'
'author': 'drmaemi'
```
</p>
<p>

이후, 백엔드 시작점인 index.js 파일을 생성하고 `npm install express --save`로 로컬에 express.js를 다운받는다. 그러면 node_modules 폴더가 생성되고 package.json의 dependency에 express가 추가된다.
</p>

## 1. Hello World
<p>

index.js<br>
```javascript
// express 모듈을 import
const express = require('express');
// express 앱을 실행한다
const app = express();
const port = 5000;

app.get('/', (req, res) => res.send("Hello World ! 안녕하세요 !"));

app.listen(port, () => console.log(`Example app listening on port ${port}!`));
```
</p>
<p>

package.json<br>
```json
"start": "node index.js",
```
</p>
<p>

각 파일에 위와 같이 코드를 추가하고 `npm start`를 터미널에 입력해 Express 웹 서버를 실행한다.</p>

## 2. MongoDB 연동
### 2.1. 클러스터 생성
<p>

가장 먼저 [MongoDB 사이트](https://www.mongodb.com)에 접속해서 회원가입 후(구글 계정을 사용할 수 있다) 클러스터를 생성해야 한다.</p>

<p><div align="center">
  <figure>
      <img src="./resources/클러스터 생성 설정.png" alt="클러스터 생성 시 설정값">
      <div align="center"><figcation>[클러스터 생성 시 설정 값]</figcation></div>
  </figure>
</div></p>

### 2.2. 유저 생성
<p>

클러스터가 생성됐다면 `CONNECT`버튼을 눌러 유저를 생성한다.</p>

<p><div align="center">
  <figure>
      <img src="./resources/MongoDB 유저 생성 1.png" alt="유저 생성 1">
      <div align="center"><figcation>[유저 생성 1]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
      <img src="./resources/MongoDB 유저 생성 2.png" alt="유저 생성 2">
      <div align="center"><figcation>[유저 생성 2]</figcation></div>
  </figure>
</div></p>

<p>모든 IP에 대해 접속을 허용하려면 0.0.0.0:0으로 접근 허용해주면 된다.</p>


### 2.3. Node와 연동
<p><div align="center">
  <figure>
      <img src="./resources/몽고DB와 Node 연동 1.png" alt="Node와 연동 1">
      <div align="center"><figcation>[Node와 연동 1]</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
      <img src="./resources/몽고DB와 Node 연동 2.png" alt="Node와 연동 2">
      <div align="center"><figcation>[Node와 연동 2]</figcation></div>
  </figure>
</div></p>

<p>해당 uri은 나중에 사용한다. 우선 다음으로 mongoose에 대해 알아본다.</p>

### 2.4. Mongoose 다운
<p>노드에서 MongoDB와의 인터페이싱 기능을 제공하는 모듈인 mongoose를 다운받는다.</p>

```
npm install mongoose --save
```

<p>이후 MongoDB와의 연동을 위해 index.js에 다음과 같은 코드를 추가한다.</p>

```javascript
// MongoDB와 연동을 위한 mongoose
const mongoose = require('mongoose');
mongoose.connect('mongodb+srv://<id>:<password>@<cluster-name>.<hash-val>.mongodb.net/myFirstDatabase?retryWrites=true&w=majority', {
  useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex: true, useFindAndModify: false
}).then(() => console.log("MongoDB connected successfully"));
```

<p>connect에 첫 번째 인자로서 [Node와의 연동 2]에서 따로 구해두었던 uri을 사용한다. 이 때 password 자리에 자신이 설정했던 password를 기입해야 한다.</p>
<p>프로젝트 관리와 보안을 위해 config 디렉토리를 생성하고 dev.js(혹은 원하는 이름의 파일로)에 mongoDB 접속 uri을 저장한다.</p>

### 2.5. 환경변수 proces.env.NODE_ENV
<p>개발을 할 때는 local 환경에서 development mode로 진행하고, 클라우드 서비스를 통해 deploy한 후에는 production mode로 개발할 수 있다. 두 가지 경우 정보를 가져오는 루트가 각각 다르므로 정보도 달리 저장해야 한다.</p>
<p>

`process.env.NODE_ENV` 값이 development mode에서는 `development`, production mode에서는 `production`을 가지므로 다음과 같은 파일들을 config 디렉토리 하위에 구성해놓는다.</p>

<p>

keys.js<br>
```javascript
if (process.env.NODE_ENV == 'production') {
  module.exports = require('./prod');
}
else {
  module.exports = require('./dev');
}
```
</p>
<p>

dev.js<br>
```javascript
module.exports = {
  MongoURI: 'mongodb+srv://<id>:<password>@<cluster-name>.<hash-val>.mongodb.net/myFirstDatabase?retryWrites=true&w=majority'
}
```
</p>
<p>

prod.js<br>
```javascript
module.exports = {
  mongoURI: process.env.MONGO_URI
}
```
</p>
<p>이후 index.js에서 다음과 같이 개발 mode에 따라 적절히 MongoDB에 접속할 수 있다.</p>

index.js<br>
```javascript
// 개발 mode에 따라 적절히 DB에 연동
const db = require('./config/keys');
// MongoDB와 연동을 위한 mongoose
const mongoose = require('mongoose');
mongoose.connect(db.MongoURI, {
  useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex: true, useFindAndModify: false
}).then(() => console.log("MongoDB connected successfully"))
.catch(err => console.log(err));
```