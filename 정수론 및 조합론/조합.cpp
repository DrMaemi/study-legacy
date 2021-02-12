#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
typedef vector<int> V;
typedef long long ll;

int N, K;
int numbers[1001];
bool visited[1001];
ll memo[1001][1001];
vector<V> cases;

void get_cases(int depth, int cursor, V v) {
    if (depth == K) {
        cases.push_back(v); return;
    }
    if (N-cursor < K-depth) return;
    for (int i=cursor; i<N; i++) {
        v.push_back(numbers[i]);
        get_cases(depth+1, i+1, v);
        v.pop_back();
    }
}

void print_cases() {
    cout << "print_cases():\n";
    for (int i=0; i<cases.size(); i++) {
        for (int j=0; j<3; j++) {
            cout << cases[i][j] << " ";
        }
        cout << "\n";
    }
}

ll coef(int N, int K) {
    if (!K || N == K) return 1;
    if (!memo[N][K])
        memo[N][K] = coef(N-1, K)+coef(N-1,K-1);
    return memo[N][K];
}

int main(void) {
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> numbers[i];
    clock_t start = clock();
    vector<int> v;
    get_cases(0, 0, v);
    print_cases();
    clock_t end = clock();
    printf("coefficient C(%d, %d): %d\n", N, K, coef(N, K));
    printf("real #cases: %d\n", cases.size());
    printf("total time: %d", end-start);
    return 0;
}