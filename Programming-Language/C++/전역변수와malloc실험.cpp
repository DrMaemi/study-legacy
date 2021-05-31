#include <iostream>
#include <string>
using namespace std;

void InputWorld(int** world, int r, int c) {
    string buffer;
    for (int i=0; i<r; i++) {
        cin >> buffer;
        for (int j=0; j<c; j++) {
            world[i][j] = buffer[j]-'0';
        }
    }
}

void PrintWorld(int** world, int r, int c) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << world[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int** MallocWorld(int** world, int r, int c) {
    world = (int**)malloc(sizeof(int*)*r);
    for (int i=0; i<r; i++) {
        world[i] = (int*)malloc(sizeof(int)*c);
    }
    return world;
}

int main(void) {
    int N;
    int** world;
    cin >> N;
    /* world가 전역 변수가 아닌 경우 MallocWorld가 void형이면 동작 안함. */
    /* 메모리 주소값을 반환하도록 해야 동작함. */
    world = MallocWorld(world, N, N);
    cout << "After malloc():\n";

    //cout << "Before malloc():\n";
    InputWorld(world, N, N);
    PrintWorld(world, N, N);
    return 0;
}