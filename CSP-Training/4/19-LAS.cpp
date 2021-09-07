//最长递增子序列
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int lastNum = 1 << 30, n, curr, maxLen = 0, currLen = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &curr);
        if (curr > lastNum)
        {
            currLen++;
        }
        else
        {
            currLen = 1;
        }
        maxLen = currLen > maxLen ? currLen : maxLen;
        lastNum = curr;
    }
    printf("%d", maxLen);
    return 0;
}