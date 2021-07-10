//亲和数 HDU 2040
#include <cstdio>
#include <iostream>
using namespace std;
int getFactor(const int &a);
int main()
{
    int a, b, aFactorSum, bFactorSum;
    while (cin >> a >> b)
    {
        aFactorSum = getFactor(a);
        if (aFactorSum != b)
        {
            printf("NO\n");
            continue;
        }
        bFactorSum = getFactor(b);
        if (bFactorSum == a)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
int getFactor(const int &a)
{
    int factorSum = 0;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            factorSum += i;
        }
    }
    return factorSum;
}