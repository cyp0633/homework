//Maya历法
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
string getTzolkinDayName[21] = {"ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
map<string, int> haabMonthDay = {{"pop", 0}, {"no", 20}, {"zip", 40}, {"zotz", 60}, {"tzec", 80}, {"xul", 100}, {"yoxkin", 120}, {"mol", 140}, {"chen", 160}, {"yax", 180}, {"zac", 200}, {"ceh", 220}, {"mac", 240}, {"kankin", 260}, {"muan", 280}, {"pax", 300}, {"koyab", 320}, {"cumhu", 340}, {"uayet", 360}};
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
        haabMonth = haabMonthDay[monthName];
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