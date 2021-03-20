//12 懒惰的松雅
#include <cstdio>
#include <iostream>
using namespace std;
bool checkluck(int h, int m);
int main()
{
    int th, tm, x, count = 0;
    scanf("%d%d%d", &x, &th, &tm);
    if (checkluck(th, tm))
    {
        printf("0");
        return 0;
    }
    do
    {
        count++;
        if (tm < x && th == 0)
        {
            th += 24;
        }
        if (tm < x)
        {
            th--;
            tm += 60;
        }
        tm -= x;
    } while (!checkluck(th, tm));
    printf("%d", count);
    return 0;
}
bool checkluck(int h, int m)
{
    int h1, h2, m1, m2;
    h1 = h / 10;
    h2 = h % 10;
    m1 = m / 10;
    m2 = m % 10;
    if (h1 == 7 || h2 == 7 || m1 == 7 || m2 == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}