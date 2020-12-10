//冒泡排序模板
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int num[100], n, i, j, t;
    bool ifSwap;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (j = 0; j < n - 1; j++)
    {
        ifSwap = false;
        for (i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                t = num[i];
                num[i] = num[i + 1];
                num[i + 1] = t;
                ifSwap = true;
            }
        }
        if (!ifSwap)
            break;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}