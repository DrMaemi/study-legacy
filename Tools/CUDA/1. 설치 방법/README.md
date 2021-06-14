# CUDA 설치 방법
<p>NVIDIA GPU를 이용하는 CUDA를 설치하는 방법</p>

<br><br>

## 목차
<p>

[1. 윈도우](#1-윈도우)<br>
&nbsp; &nbsp; [1.1. CUDA 버전 확인](#11-CUDA-버전-확인)<br>
&nbsp; &nbsp; [1.2. NVIDIA 그래픽 드라이버 버전 확인](#12-NVIDIA-그래픽-드라이버-버전-확인)<br>
</p>
<p>


</p>

<br><br>

## 1. 윈도우

### 1.1. CUDA 버전 확인
<p>자신의 NVIDIA GPU에 맞는 CUDA 버전을 확인한다.<p>

<p>

[GPU 호환 CUDA 버전 확인 링크](https://developer.nvidia.com/cuda-gpus)
</p>

<br><br>

### 1.2. NVIDIA 그래픽 드라이버 버전 확인
<p>CUDA 설치 시 NVIDIA 그래픽 드라이버도 같이 설치한다. 충돌을 방지하고자 한다면 CUDA를 설치하기 전에 그래픽 드라이버를 삭제한 후 CUDA를 설치하는 것이 좋다.</p>

<p>그래픽 드라이버를 삭제하기 싫다면 본인이 사용해야 할 CUDA 버전과 호환되는 그래픽 드라이버 버전을 확인한다.</p>

<div align="center">
  <figure>
      <img src="./resources/1.png" alt="그림1">
      <div align="center"><figcation>CUDA 호환 그래픽 드라이버 버전</figcation></div>
  </figure>
</div>

<br>

<p>내 엔비디아 그래픽 드라이버 버전도 확인한다. 엔비디아 제어판 > 좌측 하단의 시스템 정보 클릭 순으로 확인할 수 있다.</p>

<br><br>

### 1.3. CUDA 다운로드
<p>확인이 모두 끝났다면 자신의 GPU에 맞는 CUDA Toolkit을 다운로드 받는다.</p>
<p>

[CUDA Toolkit 다운로드 링크](https://developer.nvidia.com/cuda-toolkit-archive)
</p>

<p>그 다음 NVIDIA DEVELOPER 웹 사이트에 회원가입을 해야 cuDNN SDK를 다운받을 수 있다.</p>
<p>

[cuDNN 다운로드 링크](https://developer.nvidia.com/cudnn)
</p>

<p>
  <div align="center">
    <figure>
        <img src="./resources/2.png" alt="그림2">
        <div align="center"><figcation>cuDNN SDK 다운</figcation></div>
    </figure>
  </div>
</p>

<br>

<p>
  <div align="center">
    <figure>
        <img src="./resources/3.png" alt="그림3">
        <div align="center"><figcation>본인 CUDA Toolkit 버전에 맞게 다운</figcation></div>
    </figure>
  </div>
</p>