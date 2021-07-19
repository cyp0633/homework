//01串
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int num[100], sum, maxsum = 0, oneCount = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; i++) //枚举左端点
    {
        for (int j = i; j < n; j++) //枚举右端点
        {
            sum = 0;
            for (int k = 0; k < i; k++) //之前
            {
                sum += num[k];
            }
            for (int k = i; k <= j; k++) //中间
            {
                sum += 1 - num[k];
            }
            for (int k = j + 1; k < n; k++) //之后
            {
                sum += num[k];
            }
            if (sum > maxsum)
            {
                maxsum = sum;
            }
        }
    }
    printf("%d", maxsum);
    return 0;
}