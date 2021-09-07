//疫情期间
#include <cstdio>
#include <iostream>
using namespace std;
int n, minRest = 1 << 30, a[101];
void dfs(int day, int rest, int lastDay);
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(1, 0, 0);
    printf("%d", minRest);
    return 0;
}
void dfs(int day, int rest, int lastDay) //lastDay 0 = 没干 1 = 编程 2 = 健身
{
    if (day == n + 1)
    {
        minRest = rest < minRest ? rest : minRest;
        return;
    }
    if (rest > minRest)
    {
        return;
    }
    if (!(a[day] == 0 || (a[day] == 1 && lastDay == 1) || (a[day] == 2 && lastDay == 2))) //不是必须休息
    {
        switch (a[day])
        {
        case 1:
            if (lastDay != 1)
            {
                dfs(day + 1, rest, 1);
            }
            break;
        case 2:
            if (lastDay != 2)
            {
                dfs(day + 1, rest, 2);
            }
            break;
        case 3:
            if (lastDay != 1)
            {
                dfs(day + 1, rest, 1);
            }
            if (lastDay != 2)
            {
                dfs(day + 1, rest, 2);
            }
            break;
        }
    }
    dfs(day + 1, rest + 1, 0); //都可以休息
    return;
}