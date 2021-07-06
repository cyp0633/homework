//计算校验码
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
char getVeri(int num[], const int &base, const int &len);
int getDecimal(const char &c);
char getNumChar(const int &n);
int main()
{
    int T, base, num[100001], len;
    string numStr;
    scanf("%d", &T);
    while (T--)
    {
        memset(num, 0, sizeof(num));//这里一定要MEMSET清空num数组！
        scanf("%d", &base);
        cin >> numStr;
        len = numStr.length();
        for (int i = 0; i < len; i++)
        {
            num[i] = getDecimal(numStr[i]);
        }
        char veri = getVeri(num, base, len);
        putchar(veri);
        putchar('\n');
    }
    return 0;
}
char getVeri(int num[], const int &base, const int &len)
{
    for (int i = 0; i < len; i++)
    {
        num[i + 1] += num[i] % (base - 1) * base;
        num[i] /= (base - 1);
    }
    int veriNum;
    for (veriNum = 0; veriNum < base; veriNum++)
    {
        if ((num[len] + veriNum) % (base - 1) == 0)
        {
            break;
        }
    }
    //itoa(veriNum, &veriChar, base); itoa IS NOT ISO C++! IT'S JUST GNU C++
    return getNumChar(veriNum);
}
int getDecimal(const char &c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return c - 'a' + 10;
}
char getNumChar(const int &n)
{
    if (n < 10)
    {
        return n + '0';
    }
    return n - 10 + 'a';
}