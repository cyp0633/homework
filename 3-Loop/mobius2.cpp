//莫比乌斯函数
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int ss(int x);
int main()
{
    int y, n, count = 0;
    scanf("%d", &n);
    if (n == 1) //n=1的特判
    {
        printf("1");
        return 0;
    }
    if (ss(n) == 0) //素数的特判
    {
        printf("-1");
        return 0;
    }
    while (n > 1)
    {
        y = ss(n); //n是否没有其他因子了？
        if (y == 0)
        {
            count++; //剩下的这个n本身也是一个因子
            break;
        }
        else
        {
            n /= y; //除掉y这个因子
            count++;
            if (n % y == 0) //n可以被y整除2次，一定有平方因子
            {
                printf("0");
                return 0;
            }
        }
    }
    if (count % 2) //奇数个的
    {
        printf("-1");
    }
    else //偶数个的
    {
        printf("1");
    }
    return 0;
}
int ss(int x)
{
    int y, t = sqrt(x);
    for (y = 2; y <= t; y++)
    {
        if (x % y == 0)
        {
            return y;
        }
    }
    return 0;
}