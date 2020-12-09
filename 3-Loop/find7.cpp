//找7
#include <cstdio>
#include <iostream>
using namespace std;
int check(int x);
int main()
{
    int i, n;
    scanf("%d", &n);
    printf("7");
    for (i = 8; i <= n; i++)
    {
        if (check(i) || i % 7 == 0)
        {
            printf(" %d", i);
        }
    }
    return 0;
}
int check(int x)
{
    int a, b;
    while (x >= 1)
    {
        a = x % 10;
        if (a == 7)
        {
            return true;
        }
        x /= 10;
    }
    return false;
}