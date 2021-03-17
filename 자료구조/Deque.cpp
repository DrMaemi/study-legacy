#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> deq1, deq2;
    deque<int>::iterator it;
    deq1.push_front(100);
    deq1.push_back(200);
    deq1.push_back(300);
    deq1.push_front(400);
    cout << "push_front & push_back\n";
    for (int i: deq1)
        cout << i << " ";

    cout << "\n\npop_front & pop_back\n";
    deq1.pop_front(); deq1.pop_back();
    for (int i: deq1)
        cout << i << " ";
    
    cout << "\n\n접근\n";
    cout << deq1[0] << "\n";
    it = deq1.begin(); it++;
    cout << *it << "\n";

    cout << "\nfront & back\n";
    cout << deq1.front() << "\n";
    cout << deq1.back() << "\n";
}