# numpy
<p>파이썬에서 제공하는 numpy 모듈 사용법에 대해서 다룬다.</p>

<br>

### 특정 범위의 데이터 골라내기
<p>

```python
A = [[10*n+m for m in range(10)] for n in range(5)]
print(A)
```
```bash
[[0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [10, 11, 12, 13, 14, 15, 16, 17, 18, 19], [20, 21, 22, 23, 24, 25, 26, 27, 28, 29], [30, 31, 32, 33, 34, 35, 36, 37, 38, 39], [40, 41, 42, 43, 44, 45, 46, 47, 48, 49]]
```
</p>
<p>

```python
import numpy as np
B = np.array(A)
B[2, 3]
```
```bash
23
```
</p>
<p>

그러나 타입이 list인 A에서 `B[2, 3]`과 같이 튜플로 인덱스에 접근하면 오류를 반환한다.
```python
A[2, 3]
```
```bash
TypeError Traceback (most recent call last)
----> 1 A[2,3]

TypeError: list indices must be integers or slices, not tuple
```
</p>