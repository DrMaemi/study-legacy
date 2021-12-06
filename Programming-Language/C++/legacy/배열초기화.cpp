#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
 
using namespace std;
 
#define MAX 11
 
int arr[MAX][MAX] = { 0, };
 
int main(void)
{
    // 전체 초기화 : 처음에는 [0][0]을 써주고, 그 다음 칸에는 [최대 행(값) - 1][최대 열], 다음 칸에는 초기 상태의 값
    fill(&arr[0][0], &arr[MAX - 1][MAX], 7);
 
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
 
        printf("\n");
    }
 
    printf("\n\n");
    memset(arr, 0, sizeof(arr)); // 단순 0으로의 초기화는 memset이 가장 편하다.
 
    // 일부분 초기화 : 처음에는 [0][0]을 써주고, 그 다음 칸에는 [행 범위 지정][열 범위 지정], 다음 칸에는 초기 상태의 값
    fill(&arr[0][0], &arr[MAX - 5][MAX - 3], 7);
    // 예) 두 번째 칸 = [5][0] : 5행 까지만 초기화, [5][2] : 5행을 넘어서 6행의 가장 오른쪽 2개 전까지 초기화.
 
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
 
        printf("\n");
    }
 
    return 0;
}
