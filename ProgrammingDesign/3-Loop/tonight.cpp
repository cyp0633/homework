//9 今夕何夕
#include <cstdio>
#include <iostream>
using namespace std;
int run(int year);
bool check(int year);
bool hRun(int year);
int main()
{
    int a, t, i, yr, mon, day, x; //t是数据组数，yr mon day是日期
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d-%d-%d", &yr, &mon, &day);
        a = run(yr);
        if (a == 0 && mon == 2 && day == 29) //跨越百年，不一定都是闰年！28年里，不一定7个闰年！
        {
            if (hRun(yr)) //跨越百年且百年不是闰年的情况
            {
                x = yr + 12;
                printf("%d\n", x);
            }
            else
            {
                x = yr + 28;
                printf("%d\n", x);
            }
        }
        else if ((a == 0 && mon <= 2) || (a == 3 && mon >= 3)) //闰年1-2月/闰年+3 3-12月，以此类推
        {
            x = yr + 5;
            printf("%d\n", x);
        }
        else if ((a == 0 && mon >= 3) || (a == 1) || (a == 2 && mon <= 2))
        {
            x = yr + 6;
            printf("%d\n", x);
        }
        else if ((a == 2 && mon >= 3) || (a == 3 && mon <= 2))
        {
            x = yr + 11;
            printf("%d\n", x);
        }
    }
    return 0;
}
int run(int year) //这一年离上一个闰年多久了？
{
    if (check(year))
    {
        return 0;
    }
    if (check(year - 1))
    {
        return 1;
    }
    if (check(year - 2))
    {
        return 2;
    }
    if (check(year - 3))
    {
        return 3;
    }
    return 0;
}
bool check(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool hRun(int year)
{
    int hYear = (year + 28) / 100 * 100;
    if (hYear > year && !check(hYear))
    {
        return true;
    }
    else
    {
        return false;
    }
}