# VS Code SSH 원격 접속 방법

## 목차
- [원격 접속 절차](#-원격-접속-절차)
- [오류들](#오류들)
  - [Could not establish connection to "..."](#could-not-establish-connection-to-"")

## 원격 접속 절차
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/1.png" alt="1" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/2.png" alt="2" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/3.png" alt="3" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/4.png" alt="4" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/5.png" alt="5" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/6.png" alt="6" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/7.png" alt="7" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/8.png" alt="8" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/9.png" alt="9" width="70%">
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/VS Code SSH 원격 접속/10.png" alt="10" width="70%">
  </figure>
</div>
<br>

<br>

## 오류들
### Could not establish connection to "..."
<p>

아래와 같은 오류를 반환하며 위 오류 문구의 창을 보게 되는 경우
```
...
Install terminal quit with output: 프로세스에서 없는 파이프에 쓰려고 했습니다.
Received install output: 프로세스에서 없는 파이프에 쓰려고 했습니다.
Stopped parsing output early. Remaining text: 프로세스에서 없는 파이프에 쓰려고 했습니다.
Failed to parse remote port from server output
Resolver error:
...
```
</p>
<p>

이는 예전에 접속했던 대상 머신의 `HostName` 기록과 현재 접속을 시도하는 대상 머신의 `HostName`(`~/.ssh/config` 파일에 명시된)의 충돌때문에 발생하는 오류로, `~/.ssh/known*` 파일에서 관련 내용을 수정하거나 삭제해주어야 한다.
</p>