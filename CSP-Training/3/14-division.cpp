//A除以B
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string aStr;
    int a[1001], b, len;
    cin >> aStr >> b;
    len = aStr.length();
    if (len <= 1 && stoi(aStr) < b)
    {
        printf("0 %d", stoi(aStr));
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        a[i] = aStr[i] - '0';
    }
    for (int i = 0; i < len; i++)
    {
        a[i + 1] += a[i] % b * 10;
        a[i] /= b;
        if (i == 0 && a[i] == 0)
            continue;
        printf("%d", a[i]);
    }
    printf(" %d", a[len] / 10);
}