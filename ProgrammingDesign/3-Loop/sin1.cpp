//8.求sin(x)的近似值 用库函数混过去
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1415926535;
int main()
{
    int i, t, multiply = 1;
    double x, y;
    scanf("%lf", &x);
    if (x < 0)
    {
        x *= -1;
        multiply *= -1;
    }
    while (x >= 2 * pi)
    {
        x -= 2 * pi;
    }
    if (x > pi)
    {
        x -= pi;
        multiply *= -1;
    }
    y = sin(x) * multiply;
    printf("%.6f", y);
    return 0;
}