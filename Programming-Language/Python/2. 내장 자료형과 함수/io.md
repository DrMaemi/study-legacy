# Python: 입력과 출력
Python 표준 입출력

<br>

## 목차
- [두 개의 정수 입력](#두-개의-정수-입력)
- [1차원 배열 입력](#1차원-배열-입력)
- [2차원 배열 입력](#2차원-배열-입력)
- [% formatting](#formatting)


<br>

## 두 개의 정수 입력
```python
N, M = map(int, input().split())
```

<br>

## 1차원 배열 입력
입력예제
```
10 5
1 10 4 9 2 3 8 5 7 6
```
```python
N, X = map(int, input().split())
A = list(map(int, input().split()))
```
map object는 iterable하지만 색인이 불가하다. 따라서 list로 캐스팅이 필요하다.

<br>

## 2차원 배열 입력
입력예제: 배열의 길이를 주고, 2차원 배열을 입력
```
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1
```
```python
N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]
```
만약, 입력에 공백이 없다면
```python
matrix = [list(map(int, input())) for _ in range(N)] # .split() 제거
```

<br>

## % formatting
```python
print('Hello') # 1
print('100') # 2
print('%d\n' %1, end='') # 3
print('%d %d' %(1, 2)) # 4
print('%d %d %d' %(1, 2, 3)) # 5
print('%d %05d %d' %(1, 2, 0.5)) # 6
print('%10d' %3) # 7
print('%010d' %3) # 8
print('%d/%d = %f' %(1000, 3, 1000/3)) # 9
print('%d/%d = %4.1f' %(1000, 3, 1000/3)) # 10
print('%d/%d = %4.3f' %(1000000, 3, 1000000/3)) # 11
print('%.10f' %1.2) # 12
print('%08.5f' %155.99) # 13
print('%07.2f' %155.99) # 14
```

```bash
Hello # 1
100 # 2
1 # 3
1 2 # 4
1 2 3 # 5
1 00002 0 # 6
         3 # 7
0000000003 # 8
1000/3 = 333.333333 # 9
1000/3 = 333.3 # 10
1000000/3 = 333333.333 # 11
1.2000000000 # 12
155.99000 # 13
0155.99 # 14
```