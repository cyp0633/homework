//Maya历法
#include <cstdio>
#include <iostream>
using namespace std;
int getHaabMonthDay(const string &m);
string getTzolkinDayName[21] = {"ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main()
{
    int dayFromCreation, haabDay, haabMonth, haabYear, n, tzolkinName, tzolkinNumber, tzolkinYear;
    string monthName, dayStr, tempStr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempStr >> haabYear;
        size_t pos = tempStr.find('.');
        dayStr = tempStr.substr(0, pos);
        monthName = tempStr.substr(pos + 1);
        haabMonth = getHaabMonthDay(monthName);
        haabDay = stoi(dayStr);
        dayFromCreation = haabYear * 365 + haabMonth + haabDay;
        tzolkinYear = dayFromCreation / 260;
        dayFromCreation %= 260;
        tzolkinNumber = dayFromCreation % 13 + 1;
        if (tzolkinNumber == 14)
        {
            tzolkinNumber = 1;
        }
        tzolkinName = dayFromCreation % 20;
        cout << tzolkinNumber << ' ' << getTzolkinDayName[tzolkinName + 1] << ' ' << tzolkinYear << endl;
    }
}
int getHaabMonthDay(const string &m)
{
    if (m == "pop")
    {
        return 0;
    }
    if (m == "no")
    {
        return 20;
    }
    if (m == "zip")
    {
        return 40;
    }
    if (m == "zotz")
    {
        return 60;
    }
    if (m == "tzec")
    {
        return 80;
    }
    if (m == "xul")
    {
        return 100;
    }
    if (m == "yoxkin")
    {
        return 120;
    }
    if (m == "mol")
    {
        return 140;
    }
    if (m == "chen")
    {
        return 160;
    }
    if (m == "yax")
    {
        return 180;
    }
    if (m == "zac")
    {
        return 200;
    }
    if (m == "ceh")
    {
        return 220;
    }
    if (m == "mac")
    {
        return 240;
    }
    if (m == "kankin")
    {
        return 260;
    }
    if (m == "muan")
    {
        return 280;
    }
    if (m == "pax")
    {
        return 300;
    }
    if (m == "koyab")
    {
        return 320;
    }
    if (m == "cumhu")
    {
        return 340;
    }
    if (m == "uayet")
    {
        return 360;
    }
    return -1;
}