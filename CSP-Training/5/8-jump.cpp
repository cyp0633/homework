//CF1472C Long Jumps
#include <cstdio>
#include <iostream>
#include <map>
#include<cmath>
using namespace std;

int main()
{
    int t, n;
    map<long long, long long> dp;
    long long int a, maxScore;
    scanf("%d", &t);
    while (t--)
    {
        dp.clear();
        maxScore = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a);
            dp[i + a] = dp[i + a] > dp[i] + a ? dp[i + a] : dp[i] + a;
            maxScore = maxScore > dp[i + a] ? maxScore : dp[i + a];
        }
        printf("%lld\n", maxScore);
    }
    return 0;
}