#include <iostream>
#include <vector>

#define parent(x) (x-1)/2

using namespace std;

template<class T>
void swap(T &arr, int index1, int index2);
template<class T>
void heapify(T &arr);
template<class T1, class T2>
void insert_maxheap(T1 &arr, T2 element);

int main(){
    vector<int> arr;
    int n, e, tmp;
    printf("Array size:"); scanf("%d", &n);
    printf("Array:");
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    cout << "to insert:"; cin >> e;
    heapify(arr);
    insert_maxheap(arr, e);
    vector<int>::iterator iter = arr.begin();
    for (; iter != arr.end(); iter++){
        cout << *iter << " ";
    }
    return 0;
}

template<class T>
void swap(T &arr, int index1, int index2) {
    int tmp;
    tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

template<class T>
void heapify(T &arr) {
    int arrSize = arr.size();
    if (arrSize < 2) {
        return;
    }
    int parent, child;
    for (int i=1; i<arrSize; i++) {
        child = i;
        while (child != 0) {
            parent = parent(child);
            if (arr[parent] >= arr[child]) break;
            swap(arr, parent, child);
            child = parent;
        }
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