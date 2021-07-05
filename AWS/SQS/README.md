# Amazon SQS
<p>
  <div align="center">
    <figure>
        <img src="./resources/SQS 예제.png" alt="SQS 예제">
        <div align="center"><figcation>SQS 예제</figcation></div>
    </figure>
  </div>
</p>


## SQS 기능
<p>

1. 배달 받지 못한 편지 큐(Dead Letter Queue)
2. 메세지 수명 주기
3. ...
</p>

## 메시징 사용 사례
<p>

O 서비스 대 서비스 통신<br>
O 비동기 작업 항목<br>
O 상태 변경 알림<br>
X 특정 메시지 선택<br>
X 대규모 메세지
</p>
<p>
대규모 메세지 경우 Amazon S3 모듈을 이용하는 것이 더 좋다.
</p>