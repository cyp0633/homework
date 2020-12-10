//插入排序模板
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, num[100] = {0}, i, j, t, pos, reverse;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    if (num[0] > num[1])
    {
        t = num[1];
        num[1] = num[0];
        num[0] = t;
    }
    for (i = 2; i < n; i++)
    {
        pos = i;
        t = num[i];
        while (num[pos - 1] > t)
        {
            num[pos] = num[pos - 1];
            if (pos == 1)
            {
                num[1] = num[0];
                pos--;
                break;
            }
            pos--;
        }
        num[pos] = t;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}