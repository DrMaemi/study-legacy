# os 모듈
파이썬에서 운영 체제와 관련된 기능들을 수행하는 방법들을 제공한다.

<br>

## 폴더와 경로
### 지정 경로에 폴더 확인 및 생성
```python
import os

# 폴더 생성
os.mkdir('./a/if_not_exist_a_exception')

## 경로 생성
os.makedirs('./a/b/c', exist_ok=True)
```
<p>

위 두 가지 방법으로 폴더나 경로를 생성할 수 있다.<br>
`mkdir`은 `./a`까지의 경로가 존재하지 않으면 Exception을 발생시킨다. 결과적으로 마지막 한 폴더만 생성 가능하다.<br>
`makedirs`은 명시한 모든 경로가 폴더로서 생성된다. `exist_ok` 인자를 `False`(기본 값)로 설정하면, 생성하고자 한 경로가 이미 존재하는 경우 Exception을 발생시킨다. `True`로 설정하면 Exception을 발생시키지 않으며, 경로 상 이미 존재하는 폴더는 내버려둔다.
</p>

<br>

### 지정 경로 아래 파일 목록 읽기
<p>

`os.listdir()` 메서드를 이용한다.
```python
import os

# path = 'c:/dev/home/...'
path = '.'

file_list = os.listdir(path)

print(f'type(file_list): {type(file_list)}')
print(f'file_list: {file_list}')
```
```
<class 'list'>
['1. 환경 설정', '2. 내장 자료형과 함수', '3. 알고리즘에 사용되는 모듈들', '4. 기본 문법', 'logging', 'matplotlib', 'moviepy.md', 'numpy.md', 'opencv', 'os.md', 'pandas.ipynb', 'pickle.md', 'README.md', 'socket', 'time.md', '시간복잡도.md', '파일_입출력.md']
```
</p>
