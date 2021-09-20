# Python: logging-tutorial

<p>

본 문서는 [Python 공식 문서 - 로깅 HOWTO](https://docs.python.org/ko/3/howto/logging.html)를 참고하여 작성했습니다.</p>
<p>로깅은 어떤 소프트웨어가 실행될 때 발생하는 이벤트를 추적하는 수단이다.</p>

상황별 도구
수행하려는 작업 | 작업을 위한 최상의 도구
:-: | :-:
일반적 사용을 위한 콘솔 출력 | `print()`
프로그램 정상 작동 중 발생하는 이벤트 보고 | `logging.info()`<br>`logging.debug()`: 비교적 자세한 출력
특정 실행시간 이벤트와 관련된 경고 발행 | `warning.warn()`: 문제를 피할 수 있고 경고를 제거하기 위해 응용 프로그램이 수정되어야 하는 경우<br>`logging.warning()`: 응용 프로그램을 수정하여 해결할 수는 없는 상황이지만 이벤트를 계속 주목해야 하는 경우</p>

## 예시
### logger 생성
<p>

```python
import logging

# logger 생성
logger = logging.getLogger("name")
```
</p>
<p>

위 "name" 에는 String이 들어간다. 아무것도 입력하지 않는 경우 **root logger**가 생성된다.</p>
<p>

**root logger**는 모든 logger의 부모와 같은 존재로, 다른 모든 logger는 설정을 변화시키지 않으면 **root logger**의 자식이다. **root logger**을 바로 사용할 수 있지만, 기능과 목적에 따라 다른 logger들을 생성하는 것이 좋다.
</p>

<br>

### level 부여
<p>

```python
logger.setLevel(logging.INFO)
```
앞서 생성한 logger에 **INFO level**을 부여한다. 앞서 말했 듯 지금 생성된 logger는 root logger를 상속받는데, **root logger의 level은 기본적으로 `WARNING`이다**. 뒤에서 설명할 **Handler**도 level을 가지는데, **Handler의 level이 낮아도 logger의 level이 높으면 무시된다**.
</p>
<p>

위 설정으로 인해 이제 이 `logger` 객체는 INFO 이상의 메세지를 출력할 수 있다.<br>
**level**을 소문자로 바꾸어 메서드로 사용하면 메세지를 출력할 수 있다.
</p>
<p>

```python
logger.info("Message")
```
위 코드를 수행하면 콘솔에 아무것도 출력되지 않는다.
현재 이 `logger`를 통해 콘솔에 출력하거나 파일에 로깅하는 등 더욱 정교하게 만들기 위해 **handler**가 필요하다.
</p>

<br>

### Handler와 Formatter 설정
<p>

**handler** 객체는 log 메세지의 **level**에 따라 적절한 log 메세지를 지정된 위치에 전달(dispatch)하는 역할을 수행한다.
</p>
<p>

logger는 **addHandler** 메서드를 통해 이러한 handler를 추가할 수 있다. **handler**는 기능과 목적에 따라 여러 개일 수 있으며, 각 **handler**는 다른 **level**과 다른 **format**을 가질 수 있다.
</p>
<p>

**handler**의 종류는 15개 정도가 있다.

<div align='center'>

종류 | 설명
:-: | :-:
StreamHandler | stream(console)에 메세지 전달
FileHandler | File(ex: info.log)에 메세지 전달
... | ...
</div>
</p>
<p>

**handler** 객체의 **level**까지 설정했다면, 이제 이 메세지를 어떤 형식으로 출력할지 결정하는 **formatter**가 필요하다.
</p>
<p>

```python
logging.Formatter(
    fmt = None, # 메세지 출력 형태. None일 경우 raw 메세지 출력
    datefmt = None, # 날짜 출력 형태. None일 경우 '%Y-%m-%d %H:%M:%S'
    style = '%' # '%', '{', '$' 중 하나. 'fmt'의 style 결정
)

stream_handler = logging.StreamHandler()
file_handler = logging.FileHandler(filename='example.log')

# formatter 객체 생성
formatter = logging.Formatter(fmt="%(asctime)s - %(name)s - %(levelname)s - %(message)s")

# handler에 level 설정
stream_handler.setLevel(logging.INFO)
file_handler.setLevel(logging.DEBUG)

# handler에 format 설정
stream_handler.setFormatter(formatter)
file_handler.setFormatter(formatter)

logger.addHandler(stream_handler)
logger.addHandler(file_handler)
```

<p>

```python
logger.debug('This message should go to the log file')
logger.info('So should this')
logger.warning('And this, too')
logger.error('And non-ASCII stuff, too, like Øresund and Malmö')
```
</p>
<p>

출력
```
2021-08-19 21:04:49,765 - name - INFO - So should this
2021-08-19 21:04:49,767 - name - WARNING - And this, too
2021-08-19 21:04:49,769 - name - INFO - And non-ASCII stuff, too, like Øresund and Malmö
--- Logging error ---
Traceback (most recent call last):
  File "C:\dev\anaconda3\envs\test\lib\logging\__init__.py", line 1028, in emit
    stream.write(msg + self.terminator)
UnicodeEncodeError: 'cp949' codec can't encode character '\xf6' in position 87: illegal multibyte sequence
Call stack:
  File "C:\dev\anaconda3\envs\test\lib\runpy.py", line 193, in _run_module_as_main
    "__main__", mod_spec)
  File "C:\dev\anaconda3\envs\test\lib\runpy.py", line 85, in _run_code
    exec(code, run_globals)
  File "C:\dev\anaconda3\envs\test\lib\site-packages\ipykernel_launcher.py", line 16, in <module>
    app.launch_new_instance()
  File "C:\dev\anaconda3\envs\test\lib\site-packages\traitlets\config\application.py", line 845, in launch_instance
    app.start()
  File "C:\dev\anaconda3\envs\test\lib\site-packages\ipykernel\kernelapp.py", line 612, in start
    self.io_loop.start()
  File "C:\dev\anaconda3\envs\test\lib\site-packages\tornado\platform\asyncio.py", line 199, in start
    self.asyncio_loop.run_forever()
  File "C:\dev\anaconda3\envs\test\lib\asyncio\base_events.py", line 541, in run_forever
    self._run_once()
  File "C:\dev\anaconda3\envs\test\lib\asyncio\base_events.py", line 1786, in _run_once
    handle._run()
show more (open the raw output data in a text editor) ...

    exec(code_obj, self.user_global_ns, self.user_ns)
  File "<ipython-input-8-aa5ee991891f>", line 5, in <module>
    logger.info('And non-ASCII stuff, too, like Øresund and Malmö')
Message: 'And non-ASCII stuff, too, like Øresund and Malmö'
Arguments: ()
```
</p>
<p>

파일 로깅 - example.log
```
2021-08-20 00:17:36,168 - name - INFO - So should this
2021-08-20 00:17:36,168 - name - WARNING - And this, too

```
</p>