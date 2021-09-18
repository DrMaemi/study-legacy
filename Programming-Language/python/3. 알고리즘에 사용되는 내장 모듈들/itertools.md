# itertools: 효율적 루핑을 위한 이터레이터 생성 모듈
본 문서는 [Python 공식 레퍼런스 - itertools](https://docs.python.org/ko/3/library/itertools.html)를 참조하여 작성했다.
<p>

이 모듈은 APL, Haskell 및 SML의 구성물들에서 영감을 얻은 여러 이터레이터 빌딩 블록을 구현한다. 각각을 파이썬에 적합한 형태로 개선했다.
</p>

<br>

## 무한루프
함수 | 인자 | 결과 | 예시
:- | :- | :- | :-
`count()` | start, (step) | start, start+step, start+2*step, ... | `count(10)` -> `10 11 12 13 14 ...`
`cycle()` | p | p[0], p[1], p[2], ..., p[len(p)-1], p[0], p[1], ... | `cycle('ABCD')` -> `A B C D A B C D A ...`

<br>

## 조합(Combination)
함수 | 인자 | 결과 | 예시
:- | :- | :- | :-
`product()` | p, q, ..., (repeat=1) | 데카르트 곱(cartesian product), 중첩된 for 루프 | `product('ABCD', repeat=2)` -> `AA AB AC AD BA BB BC BD CA CB ... DC DD`
`permutations()` | p, (r) | r-길이의 반복 요소 없이 순서를 고려하지 않은 모든 경우 | `permutations('ABCD', 2)` -> `AB AC AD BA BC BD CA CB CD DA DB DC`
`combinations()` | p, r | r-길이의 반복 요소 없이 순서를 고려한 모든 경우 | `combinations('ABCD', 2)` -> `AB AC AD BC BD CD`
`combinations_with_replacement()` | p, r | r-길이의 같은 요소 반복 가능하며 순서를 고려한 모든 경우 | `combinations('ABCD', 2)` -> `AA AB AC AD BB BC BD CC CD DD`