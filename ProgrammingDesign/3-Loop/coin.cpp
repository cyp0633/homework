//金币 NOIp PJ 2015 P1
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n = 0, i, k, last = 0, sum = 0;
    scanf("%d", &k);
    for (i = 1; i <= k; i++)
    {
        if (last == 0)
        {
            n++;
            last = n;
        }
        last--;
        sum += n;
    }
    printf("%d", sum);
    return 0;
}