# os 모듈
파이썬에서 운영 체제와 관련된 기능들을 수행하는 방법들을 제공한다.

<br>

## 폴더와 경로
### 지정 경로에 폴더 확인 및 생성
<p>

```python
# 폴더 생성
os.mkdir('./a/if_not_exist_a_exception')

## 경로 생성
os.makedirs('./a/b/c', exist_ok=True)
```
위 두 가지 방법으로 폴더나 경로를 생성할 수 있다.<br>
`mkdir`은 `./a`까지의 경로가 존재하지 않으면 Exception을 발생시킨다. 결과적으로 마지막 한 폴더만 생성 가능하다.<br>
`makedirs`은 명시한 모든 경로가 폴더로서 생성된다. `exist_ok` 인자를 `False`(기본 값)로 설정하면, 생성하고자 한 경로가 이미 존재하는 경우 Exception을 발생시킨다. `True`로 설정하면 Exception을 발생시키지 않으며, 경로 상 이미 존재하는 폴더는 내버려둔다.
</p>