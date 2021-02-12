#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int, int> p;

bool comparator(p loc1, p loc2) {
    if (loc1.x < loc2.x) return true;
    if (loc1.y < loc2.y) return true;
    return false;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, x, y; cin >> N;
    vector<p> locs;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        locs.push_back({x, y});
    }
    sort(locs.begin(), locs.end(), comparator);
    for (int i=0; i<N; i++) {
        printf("%d %d\n", locs[i].x, locs[i].y);
    }
    return 0;
}