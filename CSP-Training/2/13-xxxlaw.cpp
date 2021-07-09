//xxx定律
#include <cstdio>
#include <iostream>
using namespace std;
int transform(int n);
int main()
{
    int n, count;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        count = 0;
        while (n != 1)
        {
            n = transform(n);
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
int transform(int n)
{
    if (n % 2 == 0)
    {
        return n / 2;
    }
    return (3 * n + 1) / 2;
}