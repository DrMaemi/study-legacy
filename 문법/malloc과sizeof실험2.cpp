#include <iostream>
using namespace std;

int main(void) {
    int** world;
    cout << "sizeof(world): " << sizeof(world);
    cout << "\nsizeof(int*): " << sizeof(int*);
    world = (int**)malloc(sizeof(int*)*10);
    cout << "\nAfter malloc, sizeof(world): " << sizeof(world);
    for (int i=0; i<10; i++) {
        world[i] = (int*)malloc(sizeof(int)*10);
    }
    cout << "\nAfter full malloc, sizeof(world): " << sizeof(world);
    int _2d_arr[10][10];
    cout << "\nsizeof(_2d_arr): " << sizeof(_2d_arr);
    return 0;
    /* 결론: 동적할당한 메모리 크기는 sizeof으로 보여지지 않는다. */
}