#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
void perform();
int timeConv(int dist);
int max(int a, int b);
int main()
{
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        perform();
    }
}
void perform()
{
    int i, j, maxTime = 0, n, k;
    int tap[1000];
    scanf("%d %d", &n, &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &tap[i]);
    }
    maxTime = tap[0];
    for (i = 1; i < k; i++)
    {
        maxTime = max(timeConv(tap[i] - tap[i - 1] + 1), maxTime);
    }
    maxTime = max(maxTime, n - tap[k - 1] + 1);
    printf("%d\n", maxTime);
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int timeConv(int dist)
{
    return ceil(dist / 2.0);
}
//0.00992s