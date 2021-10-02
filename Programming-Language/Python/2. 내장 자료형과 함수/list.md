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