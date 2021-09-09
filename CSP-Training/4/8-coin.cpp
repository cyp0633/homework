//最少钱币数
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int dp[3001], value[11], m, k; //m是钱数，k是面值数
    while (cin >> m)
    {
        if (m == 0)
        {
            break;
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &value[i]);
        }
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j >= value[i])
                {
                    dp[j] = min(dp[j], dp[j - value[i]] + 1);
                }
            }
        }
        if (dp[m] <= m)
        {
            printf("%d\n", dp[m]);
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}