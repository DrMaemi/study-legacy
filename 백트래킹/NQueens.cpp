#include <stdio.h>
#include <stdlib.h>

int n, answer;
int* vertical;
int* diagonal;
int* antidiagonal;

void nqueens(int level);
bool check(int level, int i);

int main(void) {
    scanf("%d", &n);
    answer = 0;
    vertical = (int*)malloc(sizeof(int)*n);
    diagonal = (int*)malloc(sizeof(int)*(2*n-1));
    antidiagonal = (int*)malloc(sizeof(int)*(2*n-1));
    nqueens(0);
    printf("%d\n", answer);
    return 0;
}

bool check(int level, int i) {
    if (vertical[i] == 1 || antidiagonal[level+i] == 1 || diagonal[n-1+(level-i)] == 1) {
        return false;
    }
    return true;
}

void nqueens(int level) {
    if (level == n) {
        answer++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (!check(level, i)) continue;
        vertical[i] = antidiagonal[level+i] = diagonal[n-1+(level-i)] = 1;
        nqueens(level+1);
        vertical[i] = antidiagonal[level+i] = diagonal[n-1+(level-i)] = 0;
    }
}