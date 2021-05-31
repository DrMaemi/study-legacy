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