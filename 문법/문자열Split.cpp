#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define S string

V<S> split(S s) {
    V<S> r; int f = -1;
    for (int i=0; i<s.length(); i++)
        if (s[i] == '-' || s[i] == '+') {
            r.push_back(s.substr(f+1, i-f-1));
            f = i;
        }
    if (f != s.length())
        r.push_back(s.substr(f+1));
    return r;
}

void print_all(V<S> v) {
    for (S s: v) cout << s << "\n";
}

int main() {
    string s = "55-50+40";
    V<S> v = split(s);
    print_all(v);
    return 0;
}