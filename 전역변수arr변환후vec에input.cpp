#include <iostream>
#include <vector>
using namespace std;

int arr[3] = {1, 2, 3};
vector<int*> test;

void func(int* input) {
    if (input[0] == 1) input[0] = 2;
    else input[0] = 1;
    test.push_back(input);
    cout << "input:";
    for (int i=0; i<3; i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}

int main(void) {
    func(arr);
    func(arr);
    for (int i=0; i<test.size(); i++) {
        for (int j=0; j<3; j++) {
            cout << test[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}