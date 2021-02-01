#include <iostream>
#include <vector>

#define parent(x) (x-1)/2

using namespace std;

template<class T>
void print_all(vector<T> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

template<class T>
void swap(T &arr, int p, int q) {
    auto temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}

template<class T>
void min_heapify(vector<T> &arr) {
    int size = arr.size();
    if (size < 2) return;
    int parent, child;
    for (int i=1; i<size; i++) {
        child = i;
        while (child != 0) {
            parent = parent(child);
            if (arr[parent] > arr[child]) {
                swap(arr, parent, child);
                child = parent;
            }
            else break;
        }
    }
}

template<class T>
void insert_minheap(vector<T> &arr, T input) {
    arr.push_back(input);
    int parent, child;
    child = arr.size()-1;
    while (child != 0) {
        parent = parent(child);
        if (arr[parent] > arr[child]) {
            swap(arr, parent, child);
            child = parent;
        }
        else break;
    }
}

template<class T>
T minheap_pop(vector<T> &arr) {
    int parent, child, size;
    T result;
    size = arr.size();
    swap(arr, 0, size---1);
    parent = 0;
    while (parent <= size/2-1) {
        child = 2*parent+1;
        /* 자식 노드 중 더 작은 값을 가지는 노드 선택 */
        if (child+1 < size && arr[child] > arr[child+1]) {
            child++;
        }
        /* 부모 노드가 자식 노드보다 크면 교체 */
        if (arr[parent] > arr[child]) {
            swap(arr, parent, child);
            parent = child;
        }
        else break;
    }
    result = arr[size];
    arr.resize(size);
    //realloc(arr, sizeof(int)*size);
    return result;
}

template<class T>
void descending_heapsort(vector<T> &arr) {
    int parent, child;
    int cursor = arr.size();
    while (cursor > 1) { // index 2까지 정렬되었다면 모두 정렬된 것임
        parent = 0;
        while (parent <= cursor/2-1) {
            child = 2*parent+1;
            /* 자식 노드 중 작은 노드 선택 */
            if (child+1 < cursor && arr[child] > arr[child+1]) {
                child++;
            }
            /* 부모 노드가 자식 노드보다 크면 교체 */
            if (arr[parent] > arr[child]) {
                swap(arr, parent, child);
                parent = child;
            }
            else break;
        }
        // root부터 minheap 검사 완료
        swap(arr, 0, cursor---1);
    }
}

int main(void) {
    vector<int> arr = {5, 4, 3, 2, 1};

    min_heapify(arr);
    cout << "After min_heapify(), \n";
    print_all(arr);

    int input;
    cout << "To insert:"; cin >> input;

    insert_minheap(arr, input);
    cout << "After insert to min heap, \n";
    print_all(arr);
    
    minheap_pop(arr);
    cout << "After pop in min heap, \n";
    print_all(arr);

    descending_heapsort(arr);
    cout << "After descending heapsort(), \n";
    print_all(arr);

    return 0;
}