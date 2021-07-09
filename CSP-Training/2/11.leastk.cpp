//最小的k个数
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int num[200000];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    printf("%d ", num[0]);
    k--;
    if (k == 0)
        return 0;
    for (int i = 1; i < n; i++)
    {
        if (num[i] == num[i - 1])
        {
            continue;
        }
        printf("%d ", num[i]);
        k--;
        if (k == 0)
        {
            break;
        }
    }
    return 0;
}