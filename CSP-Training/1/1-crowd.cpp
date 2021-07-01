//1-1 众数
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int count[10000];
int main()
{
    int n, num, maxn;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            return 0;
        }
        maxn = 0;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            count[num]++;
        }
        for (int i = 0; i < 10000; i++)
        {
            if (count[i] > count[maxn])
            {
                maxn = i;
            }
        }
        printf("%d\n", maxn);
    }
    return 0;
}