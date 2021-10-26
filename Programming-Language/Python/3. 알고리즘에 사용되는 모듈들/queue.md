# queue: FIFO(First In First Out) 기반 자료구조
클래스 | 설명
-- | --
queue.**Queue**(*maxsize=0*) | - FIFO 큐 생성자<br> - *maxsize*가 0보다 작거나 같으면 큐 크기는 무한. 그렇지 않으면 큐의 크기가 *maxsize*에 도달했을 때 큐 항목이 소비될 때까지 삽입 불가
queue.**LifoQueue**(*maxsize=0*) | - LIFO 큐 생성자<br>- *maxsize* 설명은 **Queue**와 동일
queue.**PriorityQueue**(*maxsize=0*) | - 우선순위 큐 생성자<br>- 가장 낮은 값을 꺼낸다<br>- *maxsize* 설명은 **Queue**와 동일

<br>

## 공통 메서드
<p>

위 표에서 제시된 큐 객체(Queue, LifoQueue, Priority Queue)는 다음에 설명된 공용 메서드를 가진다.
메서드 | 설명
-- | --
.put(*item[, block=True][, timeout=None]*) | - 큐에 *item* 삽입<br>- 선택 인자 *block*이 `True`이고 *timeout*이 `None`이면 큐 공간이 생길때까지 블록
.get(*item[, block=True][, timeout=None]*) | - 큐 항목을 제거하며 반환<br>- 선택 인자 *block* = `True`, *timeout* = `None`이면 사용 가능한 항목이 생길 때까지, 즉 값을 반환할때까지 블록
.qsize() | 큐의 크기를 반환
.empty() | 큐가 비어있으면 `True`를, 그렇지 않으면 `False` 반환
.full() | 큐가 가득차면 `True`, 그렇지 않으면 `False` 반환
.get_nowait() | .get(False)와 동일
.task_done() | - 앞선 큐에 넣은 작업이 완료되었음(즉, .get()으로 항목을 제거)을 나타냄, 즉 get()이 호출될 때마다 후속적으로 해당 함수 호출<br>- 큐에 있는 항목보다 더 많이 호출되면 `ValueError` 발생<br>- join()으로 스레드가 블로킹되면, 모든 항목이 처리됐을 때(즉 .put()된 모든 항목에 대해 .task_done() 호출이 수신되면) 재개
.join() | 큐의 모든 항목을 꺼내 처리할 때까지 스레드를 블록시킴
</p>
<p>

큐에 포함된 작업이 완료될 때까지 대기하는 예시 코드
```python
import threading, queue

q = queue.Queue()

def worker():
    while True:
        item = q.get()
        print(f'Working on {item}')
        print(f'Finished {item}')
        q.task_done()

# turn-on the worker thread
threading.Thread(target=worker, daemon=True).start()

# send thirty task requests to the worker
for item in range(30):
    q.put(item)
print('All task requests sent\n', end='')

# block until all tasks are done
q.join()
print('All work completed')
```
</p>