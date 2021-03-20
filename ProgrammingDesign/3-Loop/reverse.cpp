//11 整数反转
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long int n, m = 0;
    int t, i;
    bool pos = true, if0 = true;
    ;
    scanf("%lld", &n);
    if (n < 0)
    {
        pos = false;
        n *= -1;
    }
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    while (n >= 1)
    {
        t = n % 10;
        n /= 10;
        if (t == 0 && if0)
            continue;
        if (t != 0 && if0)
            if0 = false;
        m += t;
        m *= 10;
    }
    if (!pos)
        m *= -1;
    m /= 10;
    if (m < -2147483648 || m > 2147483647)
    {
        printf("0");
        return 0;
    }
    printf("%lld", m);
    return 0;
}