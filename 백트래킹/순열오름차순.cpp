#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result;

void dfs(int depth, int pivot);

int main(void) {
    cin >> n >> m;
    dfs(0, 0);
    return 0;
}

void dfs(int depth, int pivot) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << result[i] << " ";
        } cout << "\n";
        return;
    }
    for (int i=pivot; i<n; i++) {
        result.push_back(i+1);
        dfs(depth+1, i+1);
        result.pop_back();
    }
}