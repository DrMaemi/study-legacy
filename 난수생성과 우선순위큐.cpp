#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
#define mt mt19937
#define PQ priority_queue<P,vector<P>,compare>
typedef struct Pair {
    int a, b;
} P;

struct compare {
    /* 오름차순 정렬을 위한 설정 */
    bool operator()(P& _1, P& _2) {
        if (_1.a != _2.a) return _1.a > _2.a;
        return _1.b > _2.b;
    }
};

int N; PQ pq;
mt rd = mt(chrono::steady_clock::now().time_since_epoch().count());
vector<int> test;

template<class T>
void swap(T& arr, int i, int j) {
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap(int i, int j) {
    int temp = test[i];
    test[i] = test[j];
    test[j] = temp;
}

void pq_clear() { PQ empty; swap(pq, empty); }

void print_pq() {
    int size = pq.size();
    while (size--) {
        P p = pq.top(); pq.pop();
        printf("(%d, %d) ", p.a, p.b);
    }
    cout << "\n";
}

int main(void) {
    while (1) {
        //pq_clear();
        cout << "난수 생성을 위한 N 입력: "; cin >> N;
        if (!N) break;
        uniform_int_distribution<int> ran(0, N-1);
        for (int i=0; i<N; i++) {
            int a = ran(rd), b = ran(rd);
            pq.push({a, b});
        }
        print_pq();
    }
    return 0;
}