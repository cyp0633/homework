//数的距离差
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int getDistDiff(const int &n, const int &maxn, const int &minn);
int main()
{
    int n, num[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int maxn = num[n - 1], minn = num[0], minDiff = 1 << 30 - 1, minDiffNum, diff;
    for (int i = 0; i < n; i++)
    {
        diff = getDistDiff(num[i], maxn, minn);
        if (diff < minDiff)
        {
            minDiffNum = i;
            minDiff = diff;
        }
    }
    printf("%d", num[minDiffNum]);
    return 0;
}
int getDistDiff(const int &n, const int &maxn, const int &minn)
{
    return abs(abs(maxn - n) - (n - minn));
}