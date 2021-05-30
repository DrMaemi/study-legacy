// express 모듈을 import
const express = require('express');
// express 앱을 실행한다
const app = express();

// 개발 mode에 따라 적절히 DB에 연동
const db = require('./config/keys');
// MongoDB와 연동을 위한 mongoose
const mongoose = require('mongoose');
mongoose.connect(db.MongoURI, {
  useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex: true, useFindAndModify: false
}).then(() => console.log("MongoDB connected successfully"))
.catch(err => console.log(err));

const port = 5000;
app.get('/', (req, res) => res.send("Hello World ! 안녕하세요 !"));

app.listen(port, () => console.log(`Example app listening on port ${port}!`));