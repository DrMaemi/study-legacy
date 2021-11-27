# cProfile: 파이썬 프로파일러
cProfile과 profile은 파이썬 프로그램의 결정론적 프로파일링 (deterministic profiling)을 제공한다. 프로파일(profile)은 프로그램의 여러 부분이 얼마나 자주 그리고 얼마나 오랫동안 실행되었는지를 기술하는 통계 집합이다. 이러한 통계는 pstats 모듈을 통해 보고서로 포매팅 할 수 있다.
<p>

[파이썬 프로파일러 공식 문서](https://docs.python.org/ko/3/library/profile.html)
</p>

<br>

## 기본 예제

```python
import cProfile
import re
cProfile.run('re.compile("foo|bar")')
```

<p>

결과
```
      197 function calls (192 primitive calls) in 0.002 seconds

Ordered by: standard name

ncalls  tottime  percall  cumtime  percall filename:lineno(function)
     1    0.000    0.000    0.001    0.001 <string>:1(<module>)
     1    0.000    0.000    0.001    0.001 re.py:212(compile)
     1    0.000    0.000    0.001    0.001 re.py:268(_compile)
     1    0.000    0.000    0.000    0.000 sre_compile.py:172(_compile_charset)
     1    0.000    0.000    0.000    0.000 sre_compile.py:201(_optimize_charset)
     4    0.000    0.000    0.000    0.000 sre_compile.py:25(_identityfunction)
   3/1    0.000    0.000    0.000    0.000 sre_compile.py:33(_compile)
```
</p>
<p>

설명
- `197 function calls` - 197개 호출이 관찰됨
- `192 primitive calls` - 모든 호출 중 192개는 primitive로, 이는 호출이 재귀를 통해 발생하지 않았음을 의미
- `Ordered by: standard name` - 가장 오른쪽 열의 텍스트 문자열이 출력 정렬에 사용됐음
- `ncalls` - 호출 수
- `tottime` - 해당 함수 실행에 소요된 총 시간(하위 함수 호출 및 실행 소요 시간 제외)
- `percall` - `tottime`을 `ncalls`로 나눈 몫
- `cumtime` - 해당 함수 실행과 하위 함수 호출 및 실행 소요 총 시간
- `filename:lineno(funtion)` - 함수 메타 데이터(함수가 정의된 파일 명:줄 번호(함수 명))
</p>

<br>

## 스크립트 호출 사용법
```bash
python -m cProfile [-o output_file] [-s sort_order] (-m module | myscript.py)
```
<p>

- `-o` : stdout 대신 파일에 프로파일 결과 작성
- `-s` : 출력을 정렬할 `sort_stats()` 정렬 값 중 하나를 지정(-o가 제공되지 않은 경우에만 적용)
- `-m` : 스크립트 대신 모듈이 프로파일링 되도록 지정
</p>
<p>

Python 3.7: -m 옵션이 cProfile에 추가됨<br>
Python 3.8: -m 옵션이 profile에 추가됨
</p>
<p>

pstats 모듈의 Stats 클래스에는 프로파일 결과 파일에 저장된 데이터를 조작하고 인쇄하기 위한 다양한 메서드가 있음
</p>