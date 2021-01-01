#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
vector<int> visited;
//vector<char> output;
vector<int> numberString;

void dfs(int depth);

int main(void) {
    cin >> n >> m;
}

void dfs(int depth) {
    if (depth == m) {
        //cout << output;
        return;
    }
    for (int i=0; i<n; i++) {
        if (visited[i] == 0) {

        }
    }
}   