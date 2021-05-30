# YOLOv3

## 각 프레임워크의 장단점
### 1. Darknet
<p>

**YOLO 개발자가 만든 YOLO만을 위한 프레임워크**</p>
<p>

장점: 연산이 빠르고, GPU와 CPU 연산 모두 지원<br>
단점: Linux 환경에서만 지원. 복잡하지만 환경변수, VS 등을 통해 이용 가능</p>

### 2. DarkFlow
<p>

**Darknet의 텐서플로우 버전**<br></p>
<p>

장점: 연산이 빠르고, GPU와 CPU 연산 모두 지원 + 모든 OS 지원<br>
단점: 복잡한 설치 조건</p>

### 3. OpenCV
<p>

**내장 함수를 통한 YOLO 구현**</p>
<p>

장점: 간단한 설치<br>
단점: CPU 연산만 지원</p>

<p>

**10fps 이상의 실시간 탐지 성능을 원하는 것이 아니거나, 학습된 가중치를 간단히 테스트하는 경우 OpenCV를 이용하는 것을 추천**</p>

## YOLO 파라미터 다운로드
[다운로드 링크](https://pjreddie.com/darknet/yolo/)
<p>링크에서 스크롤하며 내려가면 Performance on the COCO Dataset 에 대한 객체 탐지 성능 비교표가 있다. 이곳에서 자신에게 맞는 모델의 weights 파일과 cfg 파일을 python이 실행될 경로로 받는다.</p>
<p>

***2021-05-03 ? => names 파일도 있어야 하지 않나? 그 파일이 의미하는 것은..?**</p>

