#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int world[9][9];
struct P {
    P(int _y, int _x): x(_x), y(_y) { }
    int x, y;
};
vector<P> p;
bool done = false;

void sudoku(int cnt);

int main(void) {
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) {
        scanf("%d", &world[i][j]);
        if (world[i][j] == 0) {
            p.push_back(P(i, j));
        }
    }
    sudoku(0);
    return 0;
}

void sudoku(int cnt) {
    if (cnt == p.size()) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf("%d ", world[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    P pos = p[cnt];
    int x = pos.x, y = pos.y;
    bool marked[10] = {};
    for (int i=0; i<9; i++) {
        marked[world[y][i]] = true;
        marked[world[i][x]] = true;
    }
    int sx, sy, ex, ey;
    sx = (x/3)*3;
    sy = (y/3)*3;
    ex = sx+3;
    ey = sy+3;
    for (int i=sy; i<ey; i++) {
        for (int j=sx; j<ex; j++) {
            marked[world[i][j]] = true;
        }
    }
    for (int num=1; num<10; num++) {
        if (!marked[num]) {
            world[y][x] = num;
            sudoku(cnt+1);
            world[y][x] = 0;
        }
    }
}