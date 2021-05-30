#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct P { int pre; char o; };

void span0(string& s) {
    int l = s.length();
    for (int i=0; i<4-l; i++)
        s = '0'+s;
}

int to_int(string& s) {
    int sum = 0;
    for (char c: s) {
        int n = c-'0';
        sum = sum*10+n;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    P m[10000];
    string oper = "DSLR";
    while (T--) {
        int in, out;
        cin >> in >> out;
        fill(m, m+10000, P{-1, ' '});
        m[in] = {in, ' '};
        queue<int> q; q.push(in);
        while (m[out].pre == -1) {
            int pre = q.front(); q.pop();
            for (char o: oper) {
                string s = to_string(pre); span0(s);
                int nx;
                if (o == 'D')
                    nx = (2*pre)%10000;
                else if (o == 'S')
                    nx = pre? pre-1:9999;
                else if (o == 'L') {
                    char t = s[0];
                    for (int i=0; i<3; i++)
                        s[i] = s[i+1];
                    s[3] = t;
                    nx = to_int(s);
                }
                else if (o == 'R') {
                    char t = s[3];
                    for (int i=3; i>=1; i--)
                        s[i] = s[i-1];
                    s[0] = t;
                    nx = to_int(s);
                }
                if (m[nx].pre == -1) {
                    m[nx] = {pre, o};
                    q.push(nx);
                }
            }
        }
        stack<char> r;
        for (int i=out; i!=m[i].pre; i=m[i].pre) {
            r.push(m[i].o);
        }
        while (!r.empty()) {
            cout << r.top();
            r.pop();
        }
        cout << "\n";
    }
    return 0;
}