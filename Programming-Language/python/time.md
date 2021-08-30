# time: 파이썬에서 시간을 측정할 수 있는 모듈

## 데코레이터(@)를 활용하여 함수 실행 시간 측정
```python
import time

def logging_time(original_fn):
    def wrapper_fn(*args, **kwargs):
        start_time = time.time()
        result = original_fn(*args, **kwargs)
        end_time = time.time()
        print("--- Working Time [{}]: {} sec ---".format(original_fn.__name__, round(end_time-start_time, 3)))
        return result
    return wrapper_fn

@logging_time
def my_func1():
    print("Hello world")

# No decorator
def my_func2():
    print("Good bye")

@logging_time
def my_func3():
    print("I wanna go home")

if __name__=="__main__":
    my_func1()
    my_func2()
    my_func3()
```
결과
```
Hello world
WorkingTime[my_func1]: 0.0 sec
Good bye
I wanna go home
WorkingTime[my_func3]: 0.0 sec
```