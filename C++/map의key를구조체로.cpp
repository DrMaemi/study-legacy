#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define MAX 1000000000
struct P {
    int a, b;
    bool operator<(const P& p) const {
        if (a != p.a) return a < p.a;
        return b < p.b;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        queue<P> q; q.push({a, b});
        map<P, int> m;
        int ans = 0; bool f = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                P p = q.front(); q.pop();
                if (!p.a) { f = 1; break; }
                P n1 = {p.a/p.b, p.b};
                if (m.find(n1) == m.end()) {
                    q.push(n1); m[n1] = 0;
                }
                if (b < MAX) {
                    P n2 = {p.a, p.b+1};
                    if (m.find(n2) == m.end()) {
                        q.push(n2); m[n2] = 0;
                    }
                }
            }
            if (f) break;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}