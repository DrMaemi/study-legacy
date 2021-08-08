# Machine Learning, Artificla Intelligence
<p>오픈소스로 존재하는 다양한 ML / AI 프레임워크와 간단한 예제를 다룬다.</p>

## 환경 구성
<p>

아나콘다를 설치했다면, tensorflow 1.5, pytorch 1.12, CUDA 10 환경을 다음과 같이 구성할 수 있다.
```bash
conda create -n tfgpu-torch python=3.7 -y
conda activate tfgpu-torch
pip install tensorflow-gpu==1.15.0
conda install pytorch=1.12.0 torchvision=0.4.0 cudatoolkit=10.0 cudnn=7 -c pytorch -c conda-forge -y
```
</p>

<p>

**Cython & Cython-bbox를 윈도우에 설치하는 방법**
```
conda activate <가상환경 명>
pip install cython
pip install -e git+https://github.com/samson-wang/cython_bbox.git#egg=cython-bbox
```
</p