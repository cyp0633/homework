//20 下载文件
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int k, m, n, t, tt, d, i, j, sum, totalMin;
    scanf("%d", &tt);
    for (i = 0; i < tt; i++)
    {
        totalMin = 0;
        sum = 0;
        scanf("%d%d", &n, &k);
        for (j = 0; j < n; j++)
        {
            scanf("%d %d", &t, &d);
            totalMin += t;
            if (totalMin <= k)
            {
                continue;
            }
            if (totalMin - t <= k && totalMin > k)
            {
                sum += (totalMin - k) * d;
            }
            if (totalMin - t > k)
            {
                sum += t * d;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}