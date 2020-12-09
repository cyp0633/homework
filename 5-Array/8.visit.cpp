//拜访朋友
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
bool route[1000000];
int main()
{
    int n, m, start, end, i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &start, &end);
        start = max(0, start);
        end = min(end, m);
        for (j = start; j < end; j++)
        {
            route[j] = true;
        }
    }
    for (i = 0; i < m; i++)
    {
        if (!route[i])
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}