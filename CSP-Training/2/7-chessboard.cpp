//棋盘
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool matrix[2000][2000];
int main()
{
    int n, maxL, count[2001], i, j, k, l;
    memset(count, 0, sizeof(count));
    char temp;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = getchar();
            matrix[i][j] = (bool)(temp - '0');
        }
        if (i != n - 1)
        {
            getchar();
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) //枚举起始点
        {
            if (matrix[i][j] == 1) //黑点，可以作为起始点
            {
                maxL = (n - i) < (n - j) ? n - i : n - j; //最小离边距离作为最大边长
                for (l = 1; l <= maxL; l++)               //枚举边长
                {
                    //下面其实只需要找新加进去的两边就行了
                    for (k = j; k < j + l; k++) //下边，横坐标k，纵坐标i+l-1
                    {
                        if (matrix[i + l - 1][k] != (k - j + l) % 2)
                        {
                            break;
                        }
                    }
                    if (k != j + l) //没检查完就break了，证明这个边长不合适，再大了当然也不合适了
                    {
                        break;
                    }
                    for (k = i; k < i + l; k++) //右边，横坐标j+l-1，横坐标k
                    {
                        if (matrix[k][j + l - 1] != (k - i + l) % 2)
                        {
                            break;
                        }
                    }
                    if (k != i + l)
                    {
                        break;
                    }
                    count[l]++;
                }
            }
        }
    }
    for (int i = n; i > 0; i--)
    {
        if (count[i] != 0)
        {
            printf("%d %d", i, count[i]);
            break;
        }
    }
    return 0;
}
