# Tensorflow

<br>

## 목차
- [설치](#-설치)
- [오류들](#-오류들)

<br><br>

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

### CUDA 빌드 가능 확인
<p>

```python
import tensorflow as tf
# CUDA 빌드 가능 확인
tf.test.is_built_with_cuda()
# CUDA GPU 빌드 가능 확인
tf.test.is_built_with_gpu_support()
# 사용 가능한 GPU 기기 확인
tf.test.gpu_device_name()
```
</p>
<br>

### GPU 사용 확인
<p>

```python
import tensorflow as tf
from tensorflow.python.client import device_lib
device_lib.list_local_devices()
```
</p>

<br><br>

## 오류들
### Stuck on Successfully opened dynamic library cudnn64_7.dll
<p>

참조 - [GitHub issue](https://github.com/CorentinJ/Real-Time-Voice-Cloning/issues/654)
</p>
<p>Tensorflow 1.x 버전은 NVIDIA 30xx GPU와 호환되지 않는다. 따라서 Tensorflow 2.x 버전으로 업그레이드해야 한다.</p>