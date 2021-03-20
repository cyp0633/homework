//数小木块
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, i;
    long long int sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += i * (i + 1) / 2;
    }
    printf("%lld", sum);
    return 0;
}