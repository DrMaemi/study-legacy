#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define V vector
#define S string

V<int> setSize, p;
map<S, int> m;

// 집합의 루트를 찾는 함수
int find_parent(int i) {
    /* 현재 노드가 집합의 루트라면 바로 반환 */
    if (p[i] == i) return i;
    /* 집합의 루트가 아닌 경우, 노드의 루트를 향해 재귀 호출하며 수정 */
    return p[i] = find_parent(p[i]);
}

// 집합을 합치는 함수
void uni(int u, int v) {
    // 각 노드가 속한 집합을 찾는다.
    u = find_parent(u);
    v = find_parent(v);
    if (u != v) {
        if (setSize[u] < setSize[v])
            swap(u, v);
        p[v] = u; // v가 속한 집합의 루트를 u로 수정
        setSize[u] += setSize[v]; // 더 큰 집합에 합쳐짐
        setSize[v] = 0; // v가 속한 집합이 u가 속한 집합으로 흡수되므로
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        setSize.clear(); p.clear();
        m.clear();
        int N; cin >> N;
        int idx = 0, v[2];
        S in[2];
        while (N--) {
            cin >> in[0] >> in[1];
            for (int i=0; i<2; i++) {
                auto it = m.find(in[i]);
                if (it != m.end())
                    v[i] = it->second;
                else {
                    m.insert(make_pair(in[i], idx));
                    p.push_back(idx);
                    setSize.push_back(1);
                    v[i] = idx++;
                }
            }
            uni(v[0], v[1]);
            cout << max(setSize[find_parent(v[0])], setSize[find_parent(v[1])]) << "\n";
        }
    }
    return 0;
}