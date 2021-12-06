#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> B = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    auto it = lower_bound(B.begin(), B.end(), 85, greater<int>());
    int idx = it-B.begin();
    printf("lower_bound with greater<>() - *it:%d, idx:%d\n", *it, idx);
    it = lower_bound(A.begin(), A.end(), 4);
    printf("lower_bound - *it:%d, idx:%d\n", *it, it-A.begin());
    it = upper_bound(A.begin(), A.end(), 4);
    printf("upper_bound - *it:%d, idx:%d\n", *it, it-A.begin());
    return 0;
}