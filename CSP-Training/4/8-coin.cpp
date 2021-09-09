//最少钱币数
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int dp[11][3001], value[11], m, k; //m是钱数，k是面值数
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
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++)
        {
            dp[i][0] = 0;
            for (int j = 0; j <= m; j++)
            {
                if (j < value[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - value[i]] + 1);
                }
            }
        }
        if (dp[k][m] <= m)
        {
            printf("%d\n", dp[k][m]);
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}