//字符串排序
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int getDisorder(string str);
bool compStr(const pair<int, string> &a, const pair<int, string> &b);
int main()
{
    pair<int, string> str[100];
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        cin >> str[i].second;
        str[i].first = getDisorder(str[i].second);
    }
    stable_sort(str, str + m, compStr);
    for (int i = 0; i < m; i++)
    {
        cout << str[i].second << '\n';
    }
    return 0;
}
int getDisorder(string str)
{
    int count = 0;
    for (string::iterator i = str.begin(); i != str.end(); i++)
    {
        for (string::iterator j = i; j != str.end(); j++)
        {
            if (*j < *i)
            {
                count++;
            }
        }
    }
    return count;
}
bool compStr(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.first < b.first;
}