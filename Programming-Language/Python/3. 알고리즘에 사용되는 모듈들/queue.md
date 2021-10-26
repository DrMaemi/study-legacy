# queue: FIFO(First In First Out) 기반 자료구조
클래스 | 설명
:- | :-
queue.**Queue**(*maxsize=0*) | - FIFO 큐 생성자<br> - *maxsize*가 0보다 작거나 같으면 큐 크기는 무한. 그렇지 않으면 큐의 크기가 *maxsize*에 도달했을 때 큐 항목이 소비될 때까지 삽입 불가
queue.**LifoQueue**(*maxsize=0*) | - LIFO 큐 생성자<br>- *maxsize* 설명은 **Queue**와 동일
queue.**PriorityQueue**(*maxsize=0*) | - 우선순위 큐 생성자<br>- 가장 낮은 값을 꺼낸다<br>- *maxsize* 설명은 **Queue**와 동일

<br>