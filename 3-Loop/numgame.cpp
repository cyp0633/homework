//数字游戏
#include <cstdio>
#include <iostream>
using namespace std;
int multiply(int x);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", n);
    while (n >= 10)
    {
        n = multiply(n);
    }
    return 0;
}
int multiply(int x)
{
    int digit, sum = 1;
    while (x >= 1)
    {
        digit = x % 10;
        x /= 10;
        if (digit)
            sum *= digit;
    }
    printf(" %d", sum);
    return sum;
}