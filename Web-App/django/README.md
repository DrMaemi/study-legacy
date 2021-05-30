## Django-study

## 목차
<p>

[1. 구조와 동작 원리](#1-구조와-동작-원리)
</p>
<p>


</p>

### 1. 구조와 동작 원리
<p>

구조
- Model - 데이터 관리, 연산
- Template - 사용자가 보는 화면
- View - 중간 관리자(Controller)
</p>
<p>

동작 원리
1. 사용자가 1번 강의를 보겠다고 요청(URL 주소 입력)
2. View(중간 관리자)는 받은 요청 확인, Model에 1번 강의를 찾아달라 지시
3. Model이 DB에서 1번 강의를 찾아 View(중간 관리자)에게 전달
4. View(중간 관리자)는 1번 강의를 Template에게 전달, HTML 파일과 조합하여 화면을 사용자에게 전달
</p>
<p>Django는 MTV pattern으로 구조화되어 있다.</p>

