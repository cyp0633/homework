//最少钱币数
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int dp[3001], value[10], m, k;
    while (cin >> m)
    {
        if (m == 0)
        {
            break;
        }
        scanf("%d", &k);
        memset(value, 0, sizeof(value));
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &value[i]);
            dp[value[i]] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            if (dp[i] == 0)
            {
                continue;
            }
            for (int j = 0; j < k; j++)
            {
                if (dp[i + value[j]] == 0)
                {
                    dp[i + value[j]] = dp[i] + 1;
                }
                else
                {
                    dp[i + value[j]] = dp[i + value[j]] < (dp[i] + 1) ? dp[i + value[j]] : (dp[i] + 1); //取最小值
                }
            }
        }
        if (dp[m] != 0)
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