//13 青蛙跳
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int a, b, t, k, i;
    long long int pos;
    scanf("%lld", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &k);
        if (k % 2 == 0)
        {
            pos = (k / 2) * (a - b);
            printf("%lld\n", pos);
        }
        else
        {
            pos = floor(k / 2.0) * (a - b) + a;
            printf("%lld\n", pos);
        }
    }
    return 0;
}