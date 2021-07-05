//平均方差
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, num[10000];
    long long int sum;
    double varSum, avg;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        avg = sum * 1.0 / n;
        varSum = 0;
        for (int i = 0; i < n; i++)
        {
            varSum += pow(num[i] - avg, 2);
        }
        varSum = floor(varSum / n);
        printf("%.0lf\n", varSum);
    }
    return 0;
}