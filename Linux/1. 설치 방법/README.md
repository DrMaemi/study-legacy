# 우분투 설치 방법


<br><br>

## 목차
<p>

[1. Virtual Box](#1-Virtual-Box)
</p>
<p>

[2. AWS EC2](#2-AWS-EC2)
</p>
<p>

[3. WSL 2](#3-wsl-2)<br>
&nbsp; &nbsp; [3.1. 설치](#3-wsl-2)<br>
&nbsp; &nbsp; [3.2. 삭제](#3-wsl-2)
</p>


<br><br>

## 1. Virtual Box
<p>

참조 - [녹두장군 블로그](https://mainia.tistory.com/2379)
</p>
<br>
<p>

[Virtual Box 다운로드 링크](https://www.virtualbox.org/wiki/Downloads)에서 `Windows hosts` 링크로 다운받는다.
</p>
<p>

[우분투 다운로드 링크](https://ubuntu.com/download/desktop)에서 우분투 LTS 버전을 다운받는다.
</p>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/1.png" alt="그림1">
      <div align="center"><figcation>Virtual Box 실행 - 새로만들기</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/2.png" alt="그림2">
      <div align="center"><figcation>다음</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/3.png" alt="그림3">
      <div align="center"><figcation>메모리 설정</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/4.png" alt="그림4">
      <div align="center"><figcation>하드 디스크 생성. 기존에 만들어뒀다면 기존 것 사용 가능</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/17.png" alt="그림17">
      <div align="center"><figcation>Virtual Box 전용 하드 디스크 종류인 VDI 선택</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/5.png" alt="그림5">
      <div align="center"><figcation>동적 할당</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/6.png" alt="그림6">
      <div align="center"><figcation>가상 하드 디스크 크기 지정</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/7.png" alt="그림7">
      <div align="center"><figcation>이제 다운받은 우분투 ISO 파일을 설치해봅시다</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/8.png" alt="그림8">
      <div align="center"><figcation>설정 - 저장소 - 광학 드라이브의 종류를 그림과 같이 선택</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/9.png" alt="그림9">
      <div align="center"><figcation>우분투 ISO 파일 선택</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/10.png" alt="그림10">
      <div align="center"><figcation>가상머신 실행 - 우분투 설치</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/11.png" alt="그림11">
      <div align="center"><figcation>언어는 Korean - 101/104</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/12.png" alt="그림12">
      <div align="center"><figcation>디스크 용량을 아끼고 싶다면 최소 설치</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/13.png" alt="그림13">
      <div align="center"><figcation>아무것도 설치안된 가상 디스크이기 때문에 위와 같이</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/14.png" alt="그림14">
      <div align="center"><figcation>사용자 정보 입력</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/15.png" alt="그림15">
      <div align="center"><figcation>건너뛰기</figcation></div>
  </figure>
</div>
<br>

<div align="center">
  <figure>
      <img src="./resources/1. Virtual Box/16.png" alt="그림16">
      <div align="center"><figcation>설치 완료</figcation></div>
  </figure>
</div>
<br>
<br><br>

## 2. AWS EC2
작성 중

<br><br>

## 3. WSL 2
<p>

WSL의 주요 변경 사항
</p>
<p>

- 경량 Hiper-V 가상머신 기반으로 아키텍처 변경, 이에 따라 리눅스 시스템 콜 호환성 향상 + 기존에 돌아가지 않던 nmap 이나 lsof를 포함한 대부분의 리눅스 앱 구동 가능
- Pro 버전이 필요했던 WSL 1과 달리 Home 버전에서도 실행
- 리눅스의 file IO가 압도적으로 빨라짐
</p>

### 3.1. 설치
<p>

참조 - [Windows 10에 Linux용 Windows 하위 시스템 설치 가이드](https://docs.microsoft.com/ko-kr/windows/wsl/install-win10)
</p>
<p>위 링크에서 '수동 설치 단계' 항목 참고</p>

<br>

### 3.2. 삭제
<p>

1. Windows PowerShell 관리자 권한으로 실행
</p>
<p>

2. 기존 설치된 WSL Ubuntu 조회
```PowerShell
PS C:\WINDOWS\system> wslconfig.exe /l
Linux용 Windows 하위 시스템 배포:
Ubuntu-18.04(기본값)
```
</p>
<p>

3. 설치된 WSL 삭제
```PowerShell
PS C:\WINDOWS\system> wslconfig.exe /u Ubuntu-18.04
등록 취소 중...
```
</p>
<p>

삭제 후 제대로 삭제되었나 조회
```PowerShell
PS C:\WINDOWS\system32> wslconfig.exe /l
Linux용 Windows 하위 시스템에 배포가 설치되어 있지 않습니다.
아래의 Microsoft Store에서 배포를 설치할 수 있습니다.
https://aka.ms/wslstore
```
</p>