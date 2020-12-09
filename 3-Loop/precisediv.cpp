//1 除法的精确计算
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, pos, n, t;
    scanf("%d %d %d", &a, &b, &n);
    t = a / b;
    a = a % b * 10;
    printf("%d.", t);
    for (pos = 0; pos < n; pos++)
    {
        t = a / b;
        a = a % b * 10;
        printf("%d", t);
    }
    return 0;
}
