# Python: 기본 입출력
<p>Python으로 코딩 테스트를 준비하는 사람들이 익혀야 할 필수 테크닉들</p>

## 1. 두 개의 정수를 입력받기
<p>

```python
N, M = map(int, input().split())
```
</p>

## 2. 1차원 배열을 입력받기
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

## 3. 2차원 배열을 입력받기
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
