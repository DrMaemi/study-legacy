#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX 20001
#define INF INT_MAX/2
#define parent(x) (x-1)/2

struct Node {
	int dest;
	int cost;
};

int V, E, start;
vector<Node> adj[MAX];
vector<Node> pq;
int dist[MAX];

void initialize() {
	cin >> V >> E >> start;
	int node1, node2, cost;
	for (int i=0; i<E; i++) {
		cin >> node1 >> node2 >> cost;
		adj[node1].push_back({node2, cost});
	}
	fill(dist+1, dist+V+1, INF);
	dist[start] = 0;
	pq.push_back({start, 0});
}

template<class T>
void swap(T& arr, int p, int q) {
	auto temp = arr[p];
	arr[p] = arr[q];
	arr[q] = temp;
}

void insert_pq(Node input) {
	pq.push_back(input);
	int child = pq.size()-1;
	while (child) {
		int parent = parent(child);
		if (pq[parent].cost > pq[child].cost) {
			swap(parent, child);
			child = parent;
		}
		else break;
	}
}

Node pop_pq() {
	int cursor = pq.size();
	swap(pq, 0, cursor---1);
	Node min_node = pq[cursor];
	int parent = 0;
	while (parent <= cursor/2-1) {
		int child = 2*parent+1;
		if (child+1 < cursor && pq[child+1].cost < pq[child].cost) {
			child++;
		}
		if (pq[child].cost < pq[parent].cost) {
			swap(pq, parent, child);
			parent = child;
		}
		else break;
	}
	pq.pop_back();
	return min_node;
}

void dijkstra() {
	while (!pq.empty()) {
		Node min_node = pop_pq();
		int next = min_node.dest;
		for (int e=0; e<adj[next].size(); e++) {
			int dest = adj[next][e].dest;
			int cost = adj[next][e].cost;
			int updated = dist[next]+cost;
			int previous = dist[dest];
			if (updated < previous) {
				dist[dest] = updated;
				insert_pq({dest, updated});
			}
		}
	}
}

void print_answer() {
	for (int v=1; v<=V; v++) {
		if (dist[v] != INF) {
			cout << dist[v] << "\n";
		}
		else cout << "INF\n";
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