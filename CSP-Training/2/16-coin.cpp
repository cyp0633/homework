//金币 NOIp 2015 PJ T1
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n = 0, i, k, last = 0, sum = 0;
    while (cin >> k)
    {
        n = last = sum = 0;
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
        printf("%d %d\n", k, sum);
    }
    return 0;
}