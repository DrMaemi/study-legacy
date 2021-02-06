#include <iostream>
#include <string>
using namespace std;

int R, C;
int** world;

void InputValue(int** _2d_arr, int r, int c) {
    string buffer;
    for (int i=0; i<r; i++) {
        cin >> buffer;
        for (int j=0; j<c; j++) {
            _2d_arr[i][j] = buffer[j]-'0';
        }
    }
}

void PrintAll(int** _2d_arr, int r, int c) {
    cout << "\nPrint All: \n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << _2d_arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    cin >> R >> C;
    world = (int**)malloc(sizeof(int*)*R);
    for (int i=0; i<R; i++) {
        world[i] = (int*)malloc(sizeof(int)*C);
    }
    InputValue(world, R, C);
    PrintAll(world, R, C);
    cout << "\n\n";
    cout << "sizeof(world): " << sizeof(world);
    cout << "\nsizeof(int**): " << sizeof(int**);
    cout << "\nsizeof(int*): " << sizeof(int*);
    cout << "\nsizeof(int): " << sizeof(int);
    return 0;
}