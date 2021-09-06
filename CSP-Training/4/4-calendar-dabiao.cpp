#include <cstdio>
#include <iostream>
using namespace std;
int check(const int &year);
int main()
{
    int daysPast = 0;
    freopen("C:\\Users\\cyp0633\\OneDrive\\Code\\homework\\dabiao.txt", "w", stdout);
    for (int i = 0; i <= 7999; i++)
    {
        if (check(i + 2000))
        {
            daysPast+=366;
        }
        else
        {
            daysPast+=365;
        }
        printf("%d,",daysPast);
    }
    fclose(stdout);
}
int check(const int &year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}