#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int m, n, matrix[21][21];
    memset(matrix, 0, sizeof(matrix));
    scanf("%d %d", &m, &n);
    matrix[1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        }
    }
    printf("%d", matrix[m][n]);
    return 0;
}