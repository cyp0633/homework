//蛇形矩阵
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int matrix[101][101], n;
    memset(matrix, 0, sizeof(matrix));
    matrix[1][1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        matrix[i][1] = matrix[i - 1][1] + i - 1;
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 2; j <= 100; j++)
        {
            matrix[i][j] = matrix[i][j - 1] + i + j - 1;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}