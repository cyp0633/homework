//牛友（打表器） USACO 2011?
#include <cstdio>
#include <iostream>
using namespace std;
int ysh(int x);
int main()
{
    int i, j, m, n;
    for (i = 6; i <= 18000; i++)
    {
        m = ysh(i);
        n = ysh(m);
        if (n == i && i != m)
        {
            printf("%d,", i);
            //To output ny2 list, use:
            //printf("%d,",m);
        }
    }
}
int ysh(int x)
{
    int sum = 0;
    for (int m = 1; m < x; m++)
    {
        if (x % m == 0)
        {
            sum += m;
        }
    }
    return sum;
}