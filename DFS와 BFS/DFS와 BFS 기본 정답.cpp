#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1001
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))

using namespace std;
bool visit[MAX];

void dfs(vector<int>* vec, int start);
void bfs(vector<int>* vec, int start);

int main(void) {
    ios::sync_with_stdio(false);
    int n, m, v, node1, node2;
    cin >> n >> m >> v;
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++) {
        sortvec(adj[i]);
    }

    fill(visit, visit+MAX, false);
    dfs(adj, v);
    cout << "\n";
    fill(visit, visit+MAX, false);
    bfs(adj ,v);
    return 0;
}

void dfs(vector<int>* vec, int start) {
    visit[start] = true;
    cout << start << " ";
    for (auto &&i : vec[start]) {
        if (!visit[i]) { dfs(vec, i); }
    } 
}

void bfs(vector<int>* vec, int start) {
    queue<int> Q;
    Q.push(start);
    visit[start] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << " ";
        for (auto &&i : vec[cur]) {
            if (!visit[i]) {
                Q.push(i);
                visit[i] = true;
            }
        }
    }
}