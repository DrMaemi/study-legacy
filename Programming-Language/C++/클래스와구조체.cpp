#include <iostream>
#include <vector>
using namespace std;
typedef struct sPair {
    vector<int> a, b;
    void insert(int _a, int _b) {
        a.push_back(_a); b.push_back(_b);
    }
} sP;
typedef class cPair {
public:
    vector<int> a, b;
    void insert(int _a, int _b) {
        a.push_back(_a); b.push_back(_b);
    }
} cP;

sP sp;
cP cp;

int main(void) {
    sp.insert(1, 2);
    cp.insert(3, 4);
    cout << cp.a[0];
    return 0;
}