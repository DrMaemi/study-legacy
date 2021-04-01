#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

void print_v() {
    cout << "print_v():\n";
    for (int i=0; i<v.size(); i++)
        cout << v[i] << "\n";
    cout << "end";
}

int main(void) {
    string buf;
    while (1) {
        getline(cin, buf);
        //cin >> buf; 이것도 됨.
        if (buf == "0") break;
        v.push_back(buf);
    }
    print_v();
    return 0;
}