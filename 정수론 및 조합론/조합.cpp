#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> V;
typedef long long ll;

int numbers[] = {1, 3, 5, 7, 8};
bool visited[5];
ll memo[1001][1001];
vector<V> cases;

void get_cases(int depth, int cursor, V v) {
    if (depth == 3) {
        if (v.size() == 3)
            cases.push_back(v);
        return;
    }
    for (int i=cursor; i<5; i++) {
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
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> v;
    get_cases(0, 0, v);
    print_cases();
    cout << "coefficient C(5, 3): " << coef(5, 3) << "\n";
    cout << "real #cases: " << cases.size();
    return 0;
}