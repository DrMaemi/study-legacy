#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> answers;
vector<char> stack;

void print_answers() {
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
}

void solve(string line) {
    stack.clear();
    for (char c: line) {
        if (c == '(' || c == '[') {
            stack.push_back(c);
        }
        else if (c == ')') {
            if (stack.empty() || stack.back() != '(') {
                answers.push_back("no");
                return;
            }
            stack.pop_back();
        }
        else if (c == ']') {
            if (stack.empty() || stack.back() != '[') {
                answers.push_back("no");
                return;
            }
            stack.pop_back();
        }
    }
    if (stack.empty()) answers.push_back("yes");
    else answers.push_back("no");
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    string buf;
    while (true) {
        getline(cin, buf);
        if (buf == ".") break;
        solve(buf);
    }
    print_answers();
    return 0;
}