//8 求sinx的近似值
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1415926535;
long long int fac(int x)
{
    long long int f[16]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};
    if(x<16)return f[x];
    else return x*fac(x-1);
}
int main()
{
    double x, t = 10000.0, sum = 0;
    int i;
    int multiply = 1;
    scanf("%lf", &x);
    if (x < 0)
    {
        multiply *= -1;
        x *= -1;
    }
    while (x >= 2 * pi)
    {
        x -= 2 * pi;
    }
    if (x > pi)
    {
        multiply *= -1;
        x -= pi;
    }
    sum+=x;
    for (i = 1; fabs(t) >= 0.0000007; i++)
    {
        t = pow(x, 2 * i + 1) * 1.0 / fac(2 * i + 1);
        if (i % 2 == 1)
            t *= -1;
        sum += t;
    }
    sum*=multiply;
    printf("%.6f", sum);
    return 0;
}