//三角形的面积
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, s, a, b, c, A;
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3))
    {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
        {
            break;
        }
        a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        s = (a + b + c) / 2;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("%.6lf\n", A);
    }
    return 0;
}