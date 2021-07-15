//多项式加法
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    double a[10000], b[10000], coefficient;
    int expr;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (cin >> expr >> coefficient)
    {
        if (expr == 0 && coefficient == 0)
        {
            break;
        }
        a[expr] = coefficient;
    }
    while (cin >> expr >> coefficient)
    {
        if (expr == 0 && coefficient == 0)
        {
            break;
        }
        b[expr] = coefficient;
    }
    for (int i = 0; i < 1000; i++)
    {
        a[i] += b[i];
    }
    for (int i = 999; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            cout << i << " " << a[i] << endl;
        }
    }
    return 0;
}