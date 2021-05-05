## 1. 파이썬 가상환경 설정
### 1.1. 아나콘다 가상환경
다음과 같이 가상환경을 생성할 수 있다.
```
conda create --name(-n) [가상환경명] [설치할패키지]
```
예시<br>
```
conda create -n testenv python=3.6
```
이후 다음과 같이 가상환경 활성화, 비활성화할 수 있다.
```
conda activate testenv
conda deactivate
```
가상환경 삭제 - base(root) 계정으로 활성화(activate) 후 삭제하는 게 좋음
```
conda activate root
conda remove --name [가상환경명] --all
```

### 주피터 노트북에 가상환경 연동
<p><div align="center">
  <figure>
    <img src="./resources/가상환경-1.png" alt="가상환경-1">
    <div align="center"><figcation>파이썬 파일 생성</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/가상환경-2.png" alt="가상환경-2">
    <div align="center"><figcation>가상환경 커널이 아직 존재하지 않는다</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/가상환경-3.png" alt="가상환경-3">
    <div align="center"><figcation>testenv라는 가상환경이 존재</figcation></div>
  </figure>
</div></p>

<p>이 상태에서 testenv를 활성화하고 `jupyter --version`를 커맨드로 입력하면 ipykernel이 설치되어 있음을 확인한다.</p>
<p>

만약 그렇지 않다면 활성화한 가상환경에서 `pip install jupyter`로 설치한다.</p>

확인했다면 비활성화 후 가상환경 커널을 생성한다.
```
conda deactivate
python -m ipykernel install --user --name [가상환경명] --display-name [커널명]
```
예시<br>
```
python -m ipykernel install --user --name testenv --display-name testenv
```

<p><div align="center">
  <figure>
    <img src="./resources/가상환경-4.png" alt="가상환경-4">
    <div align="center"><figcation>결과</figcation></div>
  </figure>
</div></p>

<p><div align="center">
  <figure>
    <img src="./resources/가상환경-5.png" alt="가상환경-5">
    <div align="center"><figcation>새로고침 후 확인</figcation></div>
  </figure>
</div></p>

### 1.2. 패키지 설치하기
```
conda activate [가상환경 명]
conda install [패키지 명]
```

### 1.3. 설치된 패키지 삭제하기
```
conda uninstall [패키지 명]
```

### 1.4. 가상환경 복제
기존에 세팅해둔 가상환경에서 약간의 변경 후 사용하고 싶을 때 사용한다.
```
conda create --name [새로운 가상환경 명] --clone [기존 가상환경 명]
```