#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int income, d, a;
    scanf("%d %d", &income, &d);
    income -= d + 5000;
    if (income < 0)
    {
        printf("0");
    }
    if (0 < income && income <= 3000)
    {
        a = 0.03 * income;
        printf("%d", a);
    }
    if (3000 < income && income <= 12000)
    {
        a = 0.1 * income - 210;
        printf("%d", a);
    }
    if (12000 < income && income <= 25000)
    {
        a = 0.2 * income - 1410;
        printf("%d", a);
    }
    if (25000 < income && income <= 35000)
    {
        a = 0.25 * income - 2660;
        printf("%d", a);
    }
    if (income > 35000 && income <= 55000)
    {
        a = 0.3 * income - 4410;
        printf("%d", a);
    }
    if (55000 < income && income <= 80000)
    {
        a = 0.35 * income - 7160;
        printf("%d", a);
    }
    if (income > 80000)
    {
        a = 0.45 * income - 15160;
        printf("%d", a);
    }
    return 0;
}