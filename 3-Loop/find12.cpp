//找12
#include <cstdio>
#include <iostream>
using namespace std;
int check(int x);
int main()
{
    int i, n;
    scanf("%d", &n);
    printf("12");
    for (i = 13; i <= n; i++)
    {
        if (check(i) || i % 12 == 0)
        {
            printf(" %d", i);
        }
    }
    return 0;
}
int check(int x)
{
    int a = 0, b = 0;
    while (x >= 1)
    {
        b = a;
        a = x % 10;
        if (a == 1 && b == 2)
        {
            return true;
        }
        x /= 10;
    }
    return false;
}