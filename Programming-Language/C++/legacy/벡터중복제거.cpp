#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 1};

    cout << "Before erase duplicates:\n";
    for (int x: v) cout << x << " ";
    cout << "\n";

    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "After erase duplicates with no sorting:\n";
    for (int x: v) cout << x << " ";
    cout << "\n";

    sort(v.begin(), v.end(), greater<int>());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "After erase duplicates with sorting:\n";
    for (int x: v) cout << x << " ";

    return 0;
}