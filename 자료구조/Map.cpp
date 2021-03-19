#include <iostream>
#include <map>
using namespace std;
struct L {
    int x, y;
    bool operator<(const L& l) const {
        if (x != l.x) return x < l.x;
        return y < l.y;
    }
};

int main() {
    map<L, int> m;
    m[{1, 1}] = 3;
    // m.insert(pair<L, int>({1, 1}, 3));
    m[{1, 2}] = 1;
    // m.insert(pair<L, int>({1, 2}, 1));
    auto it = m.find({1, 1});
    /* if (it == m.end())
        cout << "Not found.\n"; */
    // else 
    cout << it->first.x << " " << it->second << "\n";
    m[{1, 1}]++;
    cout << it->first.x << " " << it->second << "\n";

    cout << "iter map:\n";
    for (auto it=m.begin(); it!=m.end(); it++)
        cout << it->first.x << " " << it->first.y << "\n";
    return 0;
}