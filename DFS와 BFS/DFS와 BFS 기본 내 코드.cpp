#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
#define all(x) x.begin(), x.end()

int N, M, start;
vector<int> adj[MAX];
bool visited[MAX] = { false, };

void Input() {
    cin >> N >> M >> start;
    int n1, n2;
    for (int i=0; i<M; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void SortVec() {
    for (int i=0; i<N; i++) {
        sort(all(adj[i]));
    }
}

void PrintAdj() {
    for (int i=1; i<=N; i++) {
        cout << "node: "<< i << "\n";
        for (int j=0; j<adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i=0; i<adj[node].size(); i++) {
        int dest = adj[node][i];
        if (!visited[dest]) {
            dfs(dest);
        }
    }
}

void bfs() {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    while (!Q.empty()) {
        int dest = Q.front();
        Q.pop();
        cout << dest << " ";
        for (int next: adj[dest]) {
            if (!visited[next]) {
                Q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    Input();
    SortVec();
    PrintAdj();
    cout << "\nANSWER:\n";
    dfs(start);
    fill(visited, visited+N+1, false);
    cout << "\n";
    bfs();
    return 0;
}