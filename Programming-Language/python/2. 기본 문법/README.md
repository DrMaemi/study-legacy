# 기본 문법
<p>파이썬 기본 문법</p>

<br>

## 목차
- [문자열 파싱](#-문자열-파싱)
- [Try-Except-Finally](#-try-except-finally)
- [슬라이싱](#-슬라이싱)

<br>

## 문자열 파싱
<p>

기본적으로 파이썬 문자열 내장 함수 split()을 사용할 수 있다.
```python
data = "This is sample"

parsed = data.split() # default - 공백(' ')을 기준으로 파싱
print(type(parsed)) # <class 'list'>
print(parsed) # ['This', 'is', 'sample]
```
</p>
<p>

응용
```python
data = "This is sample"
parsed = data.split("i", "m", "l") # 오류 반환, split()은 두 개 이상의 인자를 가질 수 없다
```
</p>

<br><br>

## Try-Except-Finally
<p>

except에서 return을 해도 최종 반환 값은 Finally의 return 값으로 결정된다.
</p>

<p>

finally에서 return 값을 명시하지 않으면 except의 return 값으로 결정된다.
```python
# test.py
def test():
    try:
        x = int(input('3의 배수를 입력하세요 : '))
        # 3의 배수가 아니면
        if x%3 != 0:
            raise Exception('3의 배수가 아님')

    except Exception as e:
        print("예외 발생")
        return False

    finally:
        print("Finally")
        # 밑 코드를 입력한 경우 True가 반환됨.
        # return True

if __name__ == '__main__':
    f = test()
    print(f)
```
결과<br>
```
3의 배수를 입력하세요 : 2
예외 발생
Finally
False
```
</p>

## 슬라이싱
<p>

- 슬라이싱(sclicing)은 연속적 객체(ex. list, tuple, string)에서 범위를 선택하여 객체를 가져오는 방법 및 표기법을 의미.
- 연속적 객체란 iterable한(즉, `__next__`와 같은 함수들을 가진) 데이터형을 의미하는 듯?
- 슬라이싱을 하면 새로운 객체를 생성한다.
</p>

<br>

### 기본 사용법
<p>

```
A[start:end:step]
```
- start: 슬라이싱을 시작할 위치
- end: 슬라이싱을 끝낼 위치. end는 포함x
- step: stride, 즉 보폭. 예제를 통해 쉽게 이해 가능
</p>
<p>

예제
```python
A = ['a', 'b', 'c', 'd', 'e']
"""
index reference:
 a    b    c    d    e
 0    1    2    3    4   # 양수인 경우
-5   -4   -3   -2   -1   # 음수인 경우
"""
```
</p>
<p>

A[start:]
```python
A[1:]
```
```bash
['b', 'c', 'd', 'e']
```
```python
A[-3:]
```
```bash
['c', 'd', 'e']
```
</p>
<p>

A[:end]
```python
A[:2]
```
```bash
['a', 'b']
```
```python
A[:-1]
```
```bash
['a', 'b', 'c', 'd']
```
</p>
<p>

A[start:end]
```python
A[2:4]
```
```bash
['c', 'd']
```
```python
A[-4:-2]
```
```bash
['b', 'c']
```
```python
A[-2:-4] # start >= end 인 경우 빈 리스트를 반환
```
```bash
[]
```
</p>
<p>

A[start:end:step]
```python
A[-5::3] # -5부터 3칸씩 이동하여 가져온다
```
```bash
['a', 'd']
```
```python
A[3:0:-1] # index 3 ~ 1까지 거꾸로 가져온다
```
```bash
['d', 'c',' b']
```
```python
A[::-1] # 전체를 거꾸로 가져온다
```
```bash
['e', 'd', 'c', 'b', 'a']
```
</p>