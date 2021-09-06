//相等的多项式
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int coef[21], factor[20], n;
void dfs(int num, int time, int currCoef);
int main()
{
    int verify[21];
    int i;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        memset(coef, 0, sizeof(coef));
        memset(verify, 0, sizeof(verify));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &factor[i]);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &verify[i]);
        }
        dfs(0, 0, 1); //第一个选数字
        for (i = 0; i < n; i++)
        {
            if (coef[i] != verify[n - i - 1])
            {
                printf("N\n");
                break;
            }
        }
        if (i == n)
        {
            printf("Y\n");
        }
    }
}
void dfs(int num, int time, int currCoef)
{
    if (num == n)
    {
        coef[time] += currCoef;
        return;
    }
    dfs(num + 1, time, currCoef * factor[num]); //这一个选数字
    dfs(num + 1, time + 1, currCoef);           //这一个选字母，次数+1
    return;
}