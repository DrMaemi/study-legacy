// express 모듈을 import
const express = require('express');
// express 앱을 실행한다
const app = express();
const port = 3000;

// app.get('/', (req, res) => res.send("Hello World ! 안녕하세요 !"));
app.get('/', (req, res) => {
  res.sendFile(__dirname+'/index.html');
});
app.get('/help', (req, res) => res.send("<h1>This is Help Page</h1>"));

app.listen(port, () => console.log(`Example app listening on port ${port}!`));