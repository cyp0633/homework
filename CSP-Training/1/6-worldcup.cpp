//世界杯来了
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
pair<string, string> splitStr(string &str, const char div);
int strToNum(string str);
struct team
{
    string name;
    int point = 0;
    int goal = 0;
    int netGoal = 0;
} t[50];
bool compTeamByScore(team a, team b);
bool compTeamByName(team a, team b);
int main()
{
    int n, hostNum, guestNum, hostGoal, guestGoal;
    pair<string, string> separatedTeamName, separatedTeamGoal;
    string teamName, teamGoal;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, t[i].name);
    }
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        cin >> teamName >> teamGoal;
        separatedTeamName = splitStr(teamName, '-');
        separatedTeamGoal = splitStr(teamGoal, ':');
        hostGoal = strToNum(separatedTeamGoal.first);
        guestGoal = strToNum(separatedTeamGoal.second);
        for (hostNum = 0; hostNum < n; hostNum++)
        {
            if (t[hostNum].name == separatedTeamName.first)
            {
                break;
            }
        }
        for (guestNum = 0; guestNum < n; guestNum++)
        {
            if (t[guestNum].name == separatedTeamName.second)
            {
                break;
            }
        }
        t[hostNum].goal += hostGoal;
        t[guestNum].goal += guestGoal;
        t[hostNum].netGoal += hostGoal - guestGoal;
        t[guestNum].netGoal += guestGoal - hostGoal;
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
    }
    sort(t, t + n, compTeamByScore);
    sort(t, t + n / 2, compTeamByName);
    for (int i = 0; i <= n / 2 - 1; i++)
    {
        cout << t[i].name << endl;
    }
    return 0;
}
pair<string, string> splitStr(string &str, const char div)
{
    string a, b;
    string::iterator i;
    for (i = str.begin(); i != str.end(); i++)
    {
        if (*i != div)
        {
            a.push_back(*i);
        }
        else
        {
            break;
        }
    }
    i++;
    for (; i != str.end(); i++)
    {
        b.push_back(*i);
    }
    return pair<string, string>(a, b);
}
int strToNum(string str)
{
    int num = 0;
    for (string::iterator i = str.begin(); i != str.end(); i++)
    {
        num *= 10;
        num += *i - '0';
    }
    return num;
}
bool compTeamByScore(team a, team b)
{
    if (a.point != b.point)
    {
        return a.point > b.point;
    }
    if (a.netGoal > b.netGoal)
    {
        return a.netGoal > b.netGoal;
    }
    return a.goal > b.goal;
}
bool compTeamByName(team a, team b)
{
    return a.name < b.name;
}