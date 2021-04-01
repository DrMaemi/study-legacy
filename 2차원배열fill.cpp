#include <iostream>
using namespace std;

void print_2d(int (*_2d)[5]) {
    // int (*_2d)[5] 대신 int _2d[][5] 가능
    cout << "print_2d():\n";
    /* int rsize = sizeof(_2d)/sizeof(_2d[0]);
    cout << "rsize : " << rsize << "\n"; */
    int csize = sizeof(_2d[0])/sizeof(int);
    cout << "csize : " << csize << "\n";
    for (int i=0; i<csize; i++) {
        for (int j=0; j<csize; j++)
            cout << _2d[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m[5][5];
    print_2d(m);
    fill(&m[0][0], &m[4][5], -1);
    print_2d(m);
    return 0;
}