//贪心的阿迪
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int maxNum = 0, count, nAv, x, k, n, m, d;
    scanf("%d %d %d %d", &n, &k, &m, &d);
    for (x = m; x >= 1; x--)
    {
        nAv = n / x;
        count = nAv / k * x;
        if (nAv % k && nAv / k + 1 <= d)
        {
            count += x;
            maxNum = max(count, maxNum);
        }
        else if (nAv % k == 0 && nAv / k <= d)
        {
            maxNum = max(count, maxNum);
        }
    }
    printf("%d", maxNum);
    return 0;
}