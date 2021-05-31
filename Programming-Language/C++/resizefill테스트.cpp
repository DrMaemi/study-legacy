#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> v;

void print_v() {
    cout << "print_v():\n";
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}

int main(void) {
    int N = 3, M = 5;
    v.resize(N);
    for (int i=0; i<N; i++) {
        v[i].resize(M);
        fill(v[i].begin(), v[i].end(), INT_MAX);
    }
    print_v();
    return 0;
}