//火星人足球赛
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct rec
{
    char team;
    int time;
    int num;
} record[90];
bool comp(rec a, rec b);
int main()
{
    string hostName, guestName;
    getline(cin, hostName);
    getline(cin, guestName);
    int n, i, j, hostCount[100] = {0}, guestCount[100] = {0}, time, num, redCount = 0;
    char team, kind;
    memset(hostCount, 0, 100);
    memset(guestCount, 0, 100);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %c %d %c", &time, &team, &num, &kind);
        if (team == 'h') //主队
        {
            hostCount[num]++;
            if (hostCount[num] >= 2 || kind == 'r')
            {
                record[redCount].team = 'h';
                record[redCount].num = num;
                record[redCount].time = time;
                redCount++;
            }
        }
        else //客场
        {
            guestCount[num]++;
            if (guestCount[num] >= 2 || kind == 'r')
            {
                record[redCount].team = 'a';
                record[redCount].num = num;
                record[redCount].time = time;
                redCount++;
            }
        }
    }
    sort(record, record + redCount, comp);
    if (redCount == 0)
    {
        printf("No Red Card");
        return 0;
    }
    for (i = 0; i < redCount; i++)
    {
        if (record[i].team == 'h') //主场
        {
            cout << hostName << ' ' << record[i].num << ' ' << record[i].time << '\n';
        }
        else
        {
            cout << guestName << ' ' << record[i].num << ' ' << record[i].time << '\n';
        }
    }
    return 0;
}
bool comp(rec a, rec b)
{
    if (a.time != b.time)
    {
        return a.time < b.time;
    }
    if (a.team != b.team)
    {
        return a.team > b.team;
    }
    return a.num > b.num;
}