//24 汉明距离
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int a, b, i;
    int a2 = 0, b2 = 0, t, dist = 0;
    scanf("%lld %lld", &a, &b);
    for (t = 31; t >= 0; t--)
    {
        a2 = 0;
        b2 = 0;
        i = pow(2, t);
        a2 = a / i;
        a %= i;
        b2 = b / i;
        b %= i;
        if (a2 != b2)
        {
            dist++;
        }
    }
    printf("%d", dist);
}