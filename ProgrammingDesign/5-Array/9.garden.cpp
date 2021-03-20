#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
void w();
int main()
{
    int t, r;
    scanf("%d", &t);
    for (r = 0; r < t; r++)
    {
        w();
    }
    return 0;
}
void w()
{
    bool water[10001] = {0}, fullWater;
    int t, tap[1000], i, j, k, n;
    scanf("%d %d", &n, &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &tap[i]);
    }
    for (t = 1; true; t++)
    {
        fullWater = true;
        for (i = 0; i < k; i++)
        {
            water[max(1, min(tap[i] - t + 1, n))] = 1;
            water[max(1, min(tap[i] + t - 1, n))] = 1;
        }
        for (i = 1; i <= n; i++)
        {
            if (!water[i])
            {
                fullWater = false;
                break;
            }
        }
        if (fullWater)
        {
            printf("%d\n", t);
            break;
        }
    }
}
//0.00839s