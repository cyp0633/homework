//逆序数
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, revCount, num[5000];
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        revCount = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (num[i] > num[j])
                {
                    revCount++;
                }
            }
        }
        printf("%d\n", revCount);
    }
    return 0;
}