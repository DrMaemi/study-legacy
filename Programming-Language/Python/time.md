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

<br>

## localtime() - 현재 시간 저장
```python
import time

now = time.localtime()

print(f"type(now): {type(now)}")
print(f"now: {now}")
print("%04d-%02d-%02d %02d:%02d:%02d" % (now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec))
```
결과
```
type(now): <class 'time.struct_time'>
now: time.struct_time(tm_year=2021, tm_mon=8, tm_mday=30, tm_hour=18, tm_min=27, tm_sec=19, tm_wday=0, tm_yday=242, tm_isdst=0)
2021-08-30 18:27:19
```
