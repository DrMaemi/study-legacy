# Tensorflow

## 설치
<p>

아나콘다 가상환경 생성
```bash
conda create -n tftest python=3.6.4 -y
conda activate tftest
```
</p>

<p>환경에 따라 다음 1, 2 중 택</p>

<p>

1. Tensorflow 2.0+ 설치
```
pip install tensorflow
```
</p>

<p>

2. Tensorflow 1.x 설치
```
conda install tensorflow-gpu=1.15 cudatoolkit=10.0 cudnn=7
```
</p>

### GPU 사용 확인
<p>

```python
from tensorflow.python.client import device_lib
device_lib.list_local_devices()
```
</p>