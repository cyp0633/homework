//1-2 错误的里程表
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int convert[10] = {0, 1, 2, 0, 3, 4, 5, 6, 0, 7};
int main()
{
    long long int t;
    long long int meter, spare[10], p, sum;
    scanf("%lld", &t);
    for (; t > 0; t--)
    {
        memset(spare, 0, sizeof(spare));
        sum = p = 0;
        scanf("%lld", &meter);
        while (meter > 0)
        {
            spare[p] = convert[meter % 10];
            meter /= 10;
            p++;
        }
        for (int i = 0; i < p; i++)
        {
            sum += spare[i] * pow(8, i);
        }
        printf("%lld\n", sum);
    }
    return 0;
}