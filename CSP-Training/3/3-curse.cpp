//魔咒词典 HDU 1880
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
pair<string, string> curse[100000];
pair<string, string> split(const string &str);
int main()
{
    string curseTemp;
    int m = 0, n, j;
    while (getline(cin, curseTemp))
    {
        if (curseTemp == "@END@")
        {
            break;
        }
        curse[m] = split(curseTemp);
        m++;
    }
    scanf("%d", &n);
    getline(cin, curseTemp);
    for (int i = 0; i < n; i++)
    {
        getline(cin, curseTemp);
        for (j = 0; j < m; j++)
        {
            if (curse[j].first == curseTemp)
            {
                cout << curse[j].second << '\n';
                break;
            }
            if (curse[j].second == curseTemp)
            {
                cout << curse[j].first.substr(1, curse[j].first.length() - 2) << '\n';
                break;
            }
        }
        if (j == m)
        {
            printf("what?\n");
        }
    }
    return 0;
}
pair<string, string> split(const string &str)
{
    int len = str.length();
    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ']')
            break;
    }
    i++;
    pair<string, string> temp;
    temp.first = str.substr(0, i);
    temp.second = str.substr(i + 1);
    return temp;
}