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