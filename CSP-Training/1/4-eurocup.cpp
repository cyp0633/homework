//欧洲冠军联赛
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
struct team
{
    string name;
    int goal = 0;
    int point = 0;
};
bool teamComp(const team &a, const team &b)
{
    if (a.point != b.point)
    {
        return a.point > b.point;
    }
    return a.goal > b.goal;
}
int main()
{
    int T, guestNum, hostNum, n, hostGoal, guestGoal;
    string hostName, temp, guestName;
    bool found;
    scanf("%d", &T);
    for (; T > 0; T--)
    {
        team t[32];
        n = 0; //重置队伍数
        for (int i = 0; i < 12; i++)
        {
            cin >> hostName >> hostGoal >> temp >> guestGoal >> guestName;
            found = false;
            for (int j = 0; j < n; j++)
            {
                if (hostName == t[j].name)
                {
                    hostNum = j;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                hostNum = n; //这个东西其实可以用指针的，当然也可以不用，简单点
                t[n].name = hostName;
                n++;
            }
            found = false;
            for (int j = 0; j < n; j++)
            {
                if (guestName == t[j].name)
                {
                    guestNum = j;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                guestNum = n;
                t[n].name = guestName;
                n++;
            }
            if (hostGoal > guestGoal)
            {
                t[hostNum].point += 3;
            }
            else if (guestGoal > hostGoal)
            {
                t[guestNum].point += 3;
            }
            else
            {
                t[hostNum].point++;
                t[guestNum].point++;
            }
            t[hostNum].goal += hostGoal - guestGoal;
            t[guestNum].goal += guestGoal - hostGoal;
        }
        sort(t, t + n, teamComp);
        cout << t[0].name << ' ' << t[1].name << endl;
    }
    return 0;
}