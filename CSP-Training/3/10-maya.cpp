//Maya历法
#include <cstdio>
#include <iostream>
using namespace std;
int getHaabMonthDay(const string &m);
string getTzolkinDayName[14]={"","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix"};
int main()
{
    int dayFromCreation, haabDay, haabMonth, haabYear, n, tzolkinDay, tzolkinMonth, tzolkinYear;
    string monthName, dayStr, tempStr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempStr >> haabYear;
        size_t pos = tempStr.find('.');
        monthName = tempStr.substr(0, pos);
        dayStr = tempStr.substr(pos + 1);
        haabMonth = getHaabMonthDay(monthName);
        haabDay = stoi(dayStr);
        dayFromCreation = haabYear * 365 + haabMonth + haabDay;
        tzolkinYear = dayFromCreation / 260;
        dayFromCreation %= 260;
        tzolkinMonth = dayFromCreation / 20;
        tzolkinDay = dayFromCreation % 13;
        cout << tzolkinMonth << ' ' << getTzolkinDayName[tzolkinDay] << ' ' << tzolkinYear << endl;
    }
}
int getHaabMonthDay(const string &m)
{
    if(m)
}