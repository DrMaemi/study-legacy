# opencv-python
<p>영상 처리를 할 수 있는 컴퓨터 비전 프레임워크</p>

<p>

키워드: `cv2.imread()`, `cv2.imshow()`, `cv2.imwrtie()`, `cv2.VideoCapture()`, `cv2.VideoWriter()`
</p>

<br>

## opencv-python 설치
<p>

```
conda create -n opencv python=3.6.4 -y
conda activate opencv
pip install opencv-python
```
</p>

<br><br>

## 이미지 읽기
<p>

`cv2.imread(fileName, flag)`
</p>
<p>

`fileName`은 **이미지 파일의 경로**를 의미하고, `flag`는 이미지 파일을 읽을 때의 옵션이다.
</p>
<p>

flag에는 총 3가지가 있다. 명시적으로 혹은 숫자를 이용해 사용한다.
- `cv2.IMREAD_COLOR` or `1`: 이미지 파일을 color로 읽는다. 투명한 부분은 무시한다. default 값
- `cv2.IMREAD_GRAYSCALE` or `0`: 이미지 파일을 gray scale로 읽는다. 실제 이미지 처리시 중간 단계로 많이 사용한다.
- `cv2.IMREAD_UNCHANGED` or `-1`: 이미지 파일을 alpha channel까지 포함하여 읽는다.
</p>
<p>코드</p>
<p>

```python
import cv2
import numpy as np

img = cv2.imread('test.jpg', cv2.IMREAD_COLOR)
```
</p>

<br><br>

## 이미지 보기
<p>

`cv2.imshow(title, image)`
</p>
<p>

- `title`: 생성될 창의 제목을 의미
- `image`: `cv2.imread()`의 return 값
</p>
<p>코드</p>
<p>

```python
cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```
</p>
<p>

- `cv2.waitKey()`: 키보드 입력을 대기하는 함수다. 인자로 0을 넘기면 입력이 있을 때까지 무한정 대기한다. 특정 시간 대기를 원하면 ms 값을 인자로 넘기면 된다. 한 편, `ESC`키를 누를 경우 27을 반환하는데, 이렇게 특정 키에 따른 반환 값을 알게 되면 키에 따라 다른 동작을 수행하는 로직을 설계할 수 있다.
- `cv2.destroyAllWindwos()`: 화면에 나타난 창을 종료시킨다.
</p>
<p>일반적으로 위 코드 세 줄은 같이 사용된다.</p>

<br><br>

## 이미지 저장
<p>

`cv2.imwrite(fileName, image)`
</p>
<p>

- `fileName`: **저장할 경로(이름)**
- `image`: `cv2.imread()`의 return 값
</p>
<p>

다음은 `ESC`키를 누르면 창을 닫고, `s`키를 누르면 이미지 파일을 저장하는 코드이다.
</p>
<p>

```python
import cv2

img = cv2.imread('test.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow('image',img)
k = cv2.waitKey(0)
if k == 27: # ESC key
    cv2.destroyAllWindow()
elif k == ord('s'): # 's' key
    cv2.imwrite('testgray.png',img)
    cv2.destroyAllWindow()
```
</p>

<br><br>

## 비디오 읽기
<p>

`cv2.VideoCapture(arg)`
</p>
<p>

`arg`에 `0`과 `1` 같은 숫자를 넘길 경우 해당 장치를 사용하겠다는 뜻이다. 보통 웹 카메라로 첫 번째 웹캠은 `0`, 두 번째 웹캠은 `1`로 지정되어 있다.
</p>
<p>

`arg`에 파일 경로(이름)을 넘기면 해당 비디오 파일을 읽어들인다.
</p>
<p>웹 캠 코드</p>
<p>

```python
import cv2

cap = cv2.VideoCapture(0)
if cap.isOpen(): # 비디오 캡쳐 객체가 정상적으로 open되었는지 확인
	print('width: {}, height : {}'.format(cap.get(3), cap.get(4))
	
while True: # 특정 키를 누를 때까지 반복
	ret, fram = cap.read() # 비디오의 한 프레임씩 읽기
	
	if ret:
		gray = cv2.cvtColor(fram, cv2.COLOR_BGR2GRAY) # 프레임을 흑백으로 변환
		cv2.imshow('video', gray)
		k == cv2.waitKey(1) & 0xFF
		if k == 27:
			break
	else:
		print('error')

cap.release() # 오픈한 캡쳐 객체를 해제
cv2.destroyAllWindows()	
```
</p>
<p>비디오 파일 읽기 코드</p>
<p>

```python
import cv2

cap = cv2.VideoCapture('test.mp4')

while(cap.isOpened()):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.imshow('frame',gray)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
```
</p>

<br><br>

## 비디오 저장
<p>

`cv2.VideoWriter(outputFile, fourcc, frame, size)`
</p>
<p>

- `outputFile`: 저장할 비디오 파일 경로(이름)
- `fourcc`: 저장 시 코덱
- `frame`: 초당 저장될 프레임
- `size`: 저장될 해상도 크기
</p>
<p>코드</p>
<p>

```python
import cv2

cap = cv2.VideoCapture(0)

fourcc = cv2.VideoWriter_fourcc(*'DIVX')
out = cv2.VideoWriter('output.avi', fourcc, 25.0, (640,480))

while (cap.isOpend()):
    ret, frame = cap.read()

    if ret:
        # 이미지 반전,  0:상하, 1 : 좌우
        frame = cv2.flip(frame, 0)

        out.write(frame)

        cv2.imshow('frame', frame)

        if cv2.waitKey(0) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
out.release()
cv2.destroyAllWindows()
```
</p>

<br><br>

## 주의할 점
<p>

`cv2.imshow()`, `cv2.waitKey()`, `cv2.destroyAllWindows()` 이 세 가지 함수는 코드 내에서 같이 사용하지 않으면 응답 없음이나 이미지가 제대로 보이지 않는 등의 문제를 일으킬 수 있다.
</p>