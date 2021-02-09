#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> p;
#define parent(x) (x-1)/2
#define child(x) 2*x+1
#define v first
#define w second

int V, E, start;
vector<vector<p>> adj;
vector<p> pq;
int* dist;
int* path;

void swap(int i, int j) {
    p temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

p pq_pop() {
    int cursor = pq.size();
    p _min = pq[0];
    swap(0, cursor---1);
    int parent = 0;
    while (parent <= cursor/2-1) {
        int child = child(parent);
        if (child+1 < cursor && pq[child+1].w < pq[child].w) {
            child++;
        }
        if (pq[child].w < pq[parent].w) {
            swap(parent, child);
            parent = child;
        }
        else break;
    }
    pq.pop_back();
    return _min;
}

void pq_insert(p input) {
    pq.push_back(input);
    int child = pq.size()-1;
    while (child) {
        int parent = parent(child);
        if (pq[child].w < pq[parent].w) {
            swap(parent, child);
            child = parent;
        }
        else break;
    }
}

void dijkstra() {
    while (!pq.empty()) {
        p _min = pq_pop();
        int next = _min.v;
        for (int e=0; e<adj[next].size(); e++) {
            int dest = adj[next][e].v;
            int cost = adj[next][e].w;
            int previous = dist[dest];
            int updated = dist[next]+cost;
            if (updated < previous) {
                dist[dest] = updated;
                path[dest] = next;
                pq_insert({dest, updated});
            }
        }
    }
}

void initialize() {
    cin >> V >> E >> start;
    adj.resize(V+1);
    dist = (int*)malloc(sizeof(int)*(V+1));
    fill(dist+1, dist+(V+1), INT_MAX);
    path = (int*)malloc(sizeof(int)*(V+1));
    fill(path+1, path+(V+1), -1);
    int u, v, w;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dist[start] = 0;
    pq.push_back({start, 0});
}

void print_answer() {
    cout << "dist:\n";
    for (int v=1; v<=V; v++) {
        if (dist[v] != INT_MAX) {
            cout << dist[v] << "\n";
        }
        else cout << "INF\n";
    }
    cout << "path:\n";
    for (int v=1; v<=V; v++) {
        cout << path[v] << " ";
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    initialize();
    dijkstra();
    print_answer();
    return 0;
}