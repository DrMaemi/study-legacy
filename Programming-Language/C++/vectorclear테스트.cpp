#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

void print_v() {
    cout << "print_v():\n";
    for (int i=0; i<v.size(); i++) {
        printf("v[%d]: ", i);
        for (int j=0; j<v[i].size(); j++)
            printf("%d ", v[i][j]);
        cout << "\n";
    }
}

int main(void) {
    int N = 5; v.resize(N);
    for (int i=0; i<N; i++) {
        v[i].push_back(i);
        v[i].push_back(i+1);
    }
    print_v(); v.clear(); print_v();
    return 0;
}