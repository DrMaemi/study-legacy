# Pickle: 데이터 직렬화 및 역직렬화 라이브러리
파이썬 Pickle 모듈은 파이썬의 자료형과 객체를 직렬화하거나 역직렬화하고 이를 저장/이용할 수 있게끔 도와준다.


<br><br>

```python
import pickle # .pkl, .pickle
l = ['a', 'b', 'c']

# save pickle
with open('data.pkl', 'wb') as fw:
    pickle.dump(l, fw)

# load pickle
with open('data.pkl', 'rb') as fr:
    data = pickle.load(fr)

print(data)
# ['a', 'b',' c']
```