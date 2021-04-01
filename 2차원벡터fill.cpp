#include <iostream>
#include <vector>
using namespace std;
#define V vector

void print_2d(V<V<int>>& _2d) {
    cout << "print_2d():\n";
    for (V<int> v: _2d) {
        for (int i: v)
            cout << i << " ";
        cout << "\n";
    }
}

int main() {
    V<V<int>> m(5);
    for (int i=0; i<5; i++)
        m[i].resize(5);
    print_2d(m);
    fill(m.begin(), m.end(), V<int>(5, -1));
    print_2d(m);
    return 0;
}