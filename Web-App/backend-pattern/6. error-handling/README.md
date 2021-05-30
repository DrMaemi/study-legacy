## PM2 설치

```
$ npm install pm2 -g
```

<p>다음과 같이 프로세스 실행 가능</p>

```
$ pm2 start app.js
```

<p>그 외 명령어들</p>

`pm2 stop [id]` ex) `pm2 stop 0`<br>
`pm2 list` `pm2 stop all` `pm2 delete all`<br>

<p>CPU 코어 수만큼 앱을 실행시키는 것은 다음과 같다</p>

```
pm2 start ./bin/www -i max
```