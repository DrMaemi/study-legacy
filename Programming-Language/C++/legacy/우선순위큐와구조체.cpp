#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define PQ priority_queue
#define V vector
struct P { char c; int cnt; };

struct cmp {
    bool operator()(P& _1, P& _2) {
        // 오름차순 정렬을 위한 대소 비교가 보통의 bool cmp() 함수과 다르다.
        if (_1.cnt != _2.cnt) return _1.cnt > _2.cnt;
        return _1.c > _2.c;
    }
};

int main() {
    PQ<P, V<P>, cmp> pq;
    pq.push({'a', 3}); pq.push({'a', 2}); pq.push({'b', 1});
    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        printf("(%c, %d) ", p.c, p.cnt);
    }
    return 0;
}