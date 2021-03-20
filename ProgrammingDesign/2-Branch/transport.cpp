#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int w, d, a;
    scanf("%d%d", &w, &d);
    w = w * d;
    if (d < 250)
        printf("%d", w);
    if (d >= 250 && d < 500)
    {
        a = w * 0.98;
        printf("%d", a);
    }
    if (d >= 500 && d < 1000)
    {
        a = w * 0.95;
        printf("%d", a);
    }
    if (d >= 1000 && d < 2000)
    {
        a = w * 0.92;
        printf("%d", a);
    }
    if (d >= 2000 && d < 3000)
    {
        a = w * 0.9;
        printf("%d", a);
    }
    if (d >= 3000)
    {
        a = w * 0.85;
        printf("%d", a);
    }
    return 0;
}