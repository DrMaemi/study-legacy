#include <iostream>
#include <vector>

#define MAX 100000
#define parent(x) (x-1)/2

using namespace std;

int N, M, A[MAX];

void swap(int* arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void max_heapify(int* arr, int size) {
    if (size < 2) return;
    int parent, child;
    for (int i=1; i<size; i++) {
        child = i;
        while (child != 0) {
            parent = parent(child);
            if (arr[parent] < arr[child]) {
                swap(arr, parent, child);
                child = parent;
            }
            else break;
        }
    }
}

void ascending_heapsort(int* max_heap, int size) {
    int parent, child;
    int cursor = size;
    while (cursor > 1) {
        parent = 0;
        while (parent <= cursor/2-1) {
            child = 2*parent+1;
            if (child+1 < cursor && max_heap[child] < max_heap[child+1]) {
                child++;
            }
            if (max_heap[parent] < max_heap[child]) {
                swap(max_heap, parent, child);
                parent = child;
            }
            else break;
        }
        swap(max_heap, 0, cursor---1);
    }
}

int binary_search_rcs(int* sorted_arr, int target, int start, int end) {
    if (start > end) {
        return 0;
    }
    int mid = (start+end)/2;
    if (sorted_arr[mid] > target) {
        return binary_search_rcs(sorted_arr, target, start, mid-1);
    }
    else if (sorted_arr[mid] < target) {
        return binary_search_rcs(sorted_arr, target, mid+1, end);
    }
    else {
        return 1;
    }
}

int binary_search_irt(int* sorted_arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start+end)/2;
        if (sorted_arr[mid] > target) {
            end = mid-1;
        }
        else if (sorted_arr[mid] < target) {
            start = mid+1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    vector<int> answers;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    max_heapify(A, N);
    ascending_heapsort(A, N);
    cin >> M;
    int target;
    for (int i=0; i<M; i++) {
        cin >> target;
        answers.push_back(binary_search_irt(A, target, 0, N-1));
    }
    for (int i=0; i<M; i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}