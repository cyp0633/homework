//可删除的点
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int pCount = 0, n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        if (x > 0)
        {
            pCount++;
        }
    }
    if (pCount <= 1 || pCount >= n - 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}