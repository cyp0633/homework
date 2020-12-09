//15 爬虫
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, u, d, time = 0;
    while (scanf("%d %d %d", &n, &u, &d))
    {
        if (n == 0 && u == 0 && d == 0)
        {
            return 0;
        }
        time = 0;
        while (n > 0)
        {
            time++;
            n -= u;
            if (n <= 0)
            {
                break;
            }
            time++;
            n += d;
        }
        printf("%d\n", time);
    }
}