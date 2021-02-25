#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#define S string
#define V vector

V<S> split(S s, char c) {
    V<S> r;
    stringstream ss(s); S t;
    while (getline(ss, t, c)) {
        r.push_back(t);
    }
    return r;
}

void print_all(V<S> v) {
    for (S s: v)
        cout << s << "\n";
}

int main() {
    S s = "abcd,efgh";
    V<S> v = split(s, ',');
    print_all(v);
    return 0;
}