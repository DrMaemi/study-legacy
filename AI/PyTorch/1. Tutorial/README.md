# PyTorch Tutorial
<p>

[링크](https://tutorials.pytorch.kr/beginner/basics/intro.html)
</p>

<br>

## 목차

[빠른 시작 - Quick Start](https://github.com/DrMaemi/Study/blob/master/AI/PyTorch/tutorial/quick-start.ipynb)

<br>><br>

## 다중프로세스 패키지 - torch.multiprocessing
[PyTorch - MultiProcessing](https://pytorch.org/docs/stable/notes/multiprocessing.html)
<p>

`torch.multiprocessing`은 파이썬 모듈 `multiprocessing`을 torch로 wrap한 모듈이다. 따라서 `import multiprocessing` 대신 `import torch.multiprocessing`으로 코드를 작성해도 무리 없이 동작한다.
</p>
<p>

`torch.multiprocessing`은 고유의 reducer를 사용하는데, 이는 서로 다른 프로세스가 같은 데이터 복사 과정 없이 공유할 수 있도록 한다.
</p>

<br><br>