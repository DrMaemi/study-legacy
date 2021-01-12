#include <iostream>
#include <vector>

using namespace std;

int zero, one;

void fibonacci(int n);

int main(void) {
    int testcase, n;
    vector<vector<int>> answers;
    cin >> testcase;
    for (int t=0; t<testcase; t++) {
        cin >> n;
        zero = one = 0;
        fibonacci(n);
        vector<int> answer = {zero, one};
        answers.push_back(answer);
    }
    for (auto it=answers.begin(); it!=answers.end(); it++) {
        zero = (*it)[0];
        one = (*it)[1];
        cout << zero << " " << one << "\n";
    }
    return 0;
}

void fibonacci(int n) {
    if (n == 0) {
        zero++;
    }
    else if (n == 1) {
        one++;
    }
    else {
        fibonacci(n-1);
        fibonacci(n-2);
    }
}