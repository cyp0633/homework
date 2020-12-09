//23 大象看朋友
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int jishu(int x);
int main()
{
    int a, x, m, count = 0;
    scanf("%d%d", &x, &m);
    x = abs(x);
    m = m * 2 - 1;
    while (x != 0)
    {
        count++;
        a = jishu(x);
        if (a > m)
        {
            x -= m;
        }
        else
        {
            x -= a;
        }
    }
    printf("%d", count);
    return 0;
}
int jishu(int x)
{
    if (x % 2 == 0)
    {
        return x / 2 * 2 - 1;
    }
    else
    {
        return x;
    }
}