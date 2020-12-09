//松雅旅馆的自动门
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int i, n, m, a, d, countdown, x, tmax, open = 0;
    bool door = false;
    bool time[100000] = {0};
    scanf("%d%d%d%d", &n, &m, &a, &d);
    for (i = 1; i <= n; i++)
    {
        time[i * a] = 1;
    }
    tmax = n * a;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &x);
        time[x] = 1;
        if (x > tmax)
        {
            tmax = x;
        }
    }
    for (int i = 1; i <= tmax; i++)
    {
        if (door)
        {
            if (countdown == 0)
                door = false;
            else
                countdown--;
        }
        if (time[i])
        {
            if (!door)
            {
                countdown = d;
                open++;
                door=true;
            }
            else
            {
                countdown--;
            }
        }
    }
    printf("%d",open);
    return 0;
}