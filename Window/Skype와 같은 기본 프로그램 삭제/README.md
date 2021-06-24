## 기본 프로그램 삭제

<br>

### 1. 스카이프(Skype) 삭제
<p>

1. Windows PowerShell **관리자 권한**으로 실행
2. 다음과 같은 명령어 입력
```PowerShell
Get-AppxPackage *skypeapp* | Remove-AppxPackage
```
</p>
