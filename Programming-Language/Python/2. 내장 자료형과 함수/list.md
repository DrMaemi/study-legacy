# Python 자료구조: List
## 1. 선언
```python
INIT = 0
W = 640 # width
H = 480 # height
C = 3 # channel
B = 100 # batch

D1 = [INIT for _ in range(W)]
D2 = [[INIT for _ in range(W)] for _ in range(H)]
D3 = [[[INIT for _ in range(W)] for _ in range(H)] for _ in range(C)]
D4 = [[[[INIT for _ in range(W)] for _ in range(H)] for _ in range(C)] for _ in range(B)]
```
List comprehension
```python
arr = [i for i in range(2, 9) if i % 2 == 0]
# [출력표현 for 요소 in 입력시퀀스 if 조건]
# arr = [2, 4, 6, 8]
```

## 2. 2차원 배열에서 특정 열(Column) 취하기
**inline for loop 방법**
```python
a = [
    [0, 1],
    [2, 3],
    [4, 5],
    [6, 7],
    [8, 9],
    ]

b = [row[0] for row in a]
print(b)
```
```
[0, 2, 4, 6, 8]
```

## 3. 리스트 순회
```python
l = [1, 2, 3, 4, 5]
for i in range(len(l)):
    print(l[i])

for i in l:
    print(i)

# range(start, end, step)을 이용해 거꾸로 순회
for i in range(len(l)-1, -1, -1):
    print(l[i])

# reversed 내장 함수를 이용해 거꾸로 순회
for i in reversed(l):
    print(i)
```

## 4. 리스트의 모든 요소들에 대해 참, 거짓 확인
<p>

- `all()` - 리스트 혹은 튜플의 **모든 요소가 참일 때**에만 `True`를 반환
- `any()` - 리스트 혹은 튜플의 요소 중 **단 하나의 요소**만 참이면 `True`를 반환
```python
>>> lst = ['1', '2', 'a', 1, 0.1]
>>> all(lst)
True
>>> lst = [[], (), {}, 0, None]
>>> any(lst)
False
>>> lst = [[], (), {}, 0, None, 1]
>>> any(lst)
True
```
</p>

## 5. 리스트를 스택 자료구조처럼 사용하기
<p>

스택 선언
```
>>> stack = [1, 2, 3]
```
</p>
<p>

원소 추가(push)
```
>>> stack.append(4)
>>> stack
[1, 2, 3, 4]
```
</p>
<p>

원소 제거(pop)
```
>>> top = stack.pop()
>>> top
4
>>> stack
[1, 2, 3]
```
</p>
<p>

원소를 제거하지 않고 top 확인
```
>>> top = stack[-1]
>>> top
3
>>> stack
[1, 2, 3]
```
</p>