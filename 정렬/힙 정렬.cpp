#include <iostream>
#include <vector>

#define parent(x) (x-1)/2

using namespace std;

template<class T1, class T2>
void swap(T1 &arr, T2 x, T2 y);
template<class T1, class T2>
void heapsort(T1 &arr, T2 n);
template<class T1, class T2>
void insert_maxheap(T1 &arr, T2 element);
template<class T>
void delete_maxheap(T &arr);

int main(void) {
    int n, tmp;
    vector<int> arr;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    heapsort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}

template<class T1, class T2>
void swap(T1 &arr, T2 x, T2 y) {
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

template<class T1, class T2>
void heapify(T1 &arr, T2 &count) {
    int parent, child;
    for (int i=1; i<count; i++) {
        child = i;
        while (child > 0) {
            parent = parent(child);
            if (arr[parent] < arr[child]) {
                swap(arr, parent, child);
                child = parent;
            }
            else break;
        }
    }
    //swap(arr, 0, --count); // 엥 이거 뭐냐?
}

template<class T1, class T2>
void heapsort(T1 &arr, T2 n) {
    int count = n;
    int parent, child;
    /* 최초 힙트리 생성 */
    heapify(arr, count);
    /* 힙 정렬 수행 */
    while (count > 1) {
        parent = 0;
        /* 자식 노드 있는 곳까지만 보면 됨 */
        while (parent <= count/2-1) {
            /* 첫 번째 자식 노드*/
            child = 2*parent+1;
            /* 자식 노드 중 큰 노드 선택 */
            if (child+1 < count && arr[child] < arr[child+1]) {
                child++;
            }
            /* 부모 노드가 자식 노드보다 작으면 교체 */
            if (arr[parent] < arr[child]) {
                swap(arr, parent, child);
                parent = child;
            }
            else break;
        }
        /* root와 마지막 교체, 사이즈 감소 */
        swap(arr, 0, count---1);
    }
}

template<class T1, class T2>
void insert_maxheap(T1 &arr, T2 element) {
    arr.push_back(element);
    int parent, child;
    child = arr.size()-1;
    while (child != 0) {
        parent = parent(child);
        if (arr[parent] >= arr[child]) break;
        swap(arr, parent, child);
        child = parent;
    }
}

template<class T>
void delete_maxheap(T &arr) {
    int parent, child, arrSize;
    arrSize = n;
    /* 먼저 Max Heap의 루트 노드(가장 큰 값)를 heap 마지막 요소와 바꿈 */
    swap(arr, 0, arrSize---1);
    realloc(arr, sizeof(int)*(arrSize));
    parent = 0;
    while (parent <= arrSize/2-1) {
        child = 2*parent+1;
        /* 자식 노드 중 큰 노트 선택 */
        if (child+1 < arrSize && arr[child] < arr[child+1]) {
            child++;
        }
        /* 부모 노드가 자식 노드보다 작으면 교체 */
        if (arr[parent] >= arr[child]) break;
        swap(arr, parent, child);
        cout << "After swap(), ";
        print_all(arr);
        parent = child;
    }
}