//组个最小数
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int num[10] = {0}, minNumNot0 = 10, temp;
    while (cin >> temp)
    {
        num[temp]++;
        if (temp != 0)
        {
            minNumNot0 = temp < minNumNot0 ? temp : minNumNot0;
        }
    }
    num[minNumNot0]--;
    putchar(minNumNot0 + '0');
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            putchar(i + '0');
        }
    }
    return 0;
}