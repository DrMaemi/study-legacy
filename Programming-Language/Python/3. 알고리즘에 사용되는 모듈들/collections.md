# collections: 컨테이너 데이터형
[공식 문서](https://docs.python.org/ko/3/library/collections.html#collections.namedtuple)
<br>

`collections`모듈은 파이썬의 범용 내장 컨테이너인 dict, list, set 및 tuple에 대한 대안을 제공하는 특수 컨테이너 데이터형을 구현한다.

<br>

클래스 | 기능
:- | :-
deque | 양쪽 끝에서 빠르게 요소를 추가 및 삭제할 수 있는 Double ended queue
namedtuple | 이름 붙은 필드를 갖는 튜플 서브 클래스를 만들기 위한 팩토리 함수
ChainMap | 여러 매핑의 단일 뷰를 만드는 딕셔너리
Counter | 해시 가능한 객체를 세는 데 사용하는 딕셔너리
OrderedDict | 항목이 추가된 순서를 기억하는 딕셔너리
defaultdict | ...
UserDict | ...
UserList | ...
UserString | ...

<br>

## deque
메서드 | 설명 | 시간복잡도 | 비고
:- | :- | :-: | :-
`append(x)` | deque 오른쪽에 요소 x 추가 | O(1) | 
`appendleft(x)` | 덱 왼쪽에 요소 x 추가 | O(1) | 
`clear()` | 모든 요소 제거 | | 
`copy()` | 얕은 복사 | |
`count(x)` | 요소 x의 개수 | O(N) | 
`extend(*iterable*)` | *iterable* 인자에서 온 요소들을 덱의 오른쪽에 추가 | O(K) | K = len(*iterable*)
`extendleft(*iterable*)` | 왼쪽에 추가. 일련의 왼쪽 추가는 *iterable* 인자의 요소들의 순서를 뒤집는 결과를 준다. | O(K) | K = len(*iterable*)
`index(x[, start[, stop]])` | 큐 내 요소 x가 위치하는 index를 반환 | O(K) | K = start - stop. start, stop 인자가 주어지지 않으면 큐 내 모든 요소 순회. 탐색 범위 내 요소 x가 존재하지 않으면 ValueError를 반환
`pop()` | 큐 내 오른쪽 끝 요소를 제거하며 해당 요소를 반환 | O(1) | 큐가 비어있을 경우 IndexError를 반환
`popleft()` | 큐 내 왼쪽 끝 요소를 제거하며 해당 요소를 반환 | O(1) | pop()과 동일
`remove(x)` | 큐 왼쪽부터 가장 먼저 발견된 요소 x 제거 | O(N) | x가 발견되지 않으면 ValueError를 반환
`rotate(k)` | 큐 내 원소를 우측으로 k만큼 이동, k가 음수인 경우 좌측으로 k 절대값만큼 이동 | O(k) | k의 기본 값은 1이며, 내부 구현은 k번 만큼 appendleft(deque.pop()) 또는 append(deque.popleft())를 수행하도록 되어있다.