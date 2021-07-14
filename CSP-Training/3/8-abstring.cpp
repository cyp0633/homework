//ab串
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int maxlen;
void dfs(int n, int length, const pair<int, char> p[], const int &pNum, int stage); //前面的a
int main()
{
    pair<int, char> p[5000];
    string str;
    string::size_type aPos = 0, bPos = 0;
    int n = 0;
    cin >> str;
    while (1)
    {
        bPos = str.find('b', aPos);
        if (bPos == string::npos)
        {
            p[n].first = str.length() - aPos;
            p[n].second = 'a';
            n++;
            break;
        }
        p[n].first = bPos - aPos;
        p[n].second = 'a';
        n++;
        aPos = str.find('a', bPos + 1);
        if (aPos == string::npos)
        {
            p[n].first = str.length() - bPos;
            p[n].second = 'b';
            n++;
            break;
        }
        p[n].first = aPos - bPos;
        p[n].second = 'b';
        n++;
    }
    dfs(0, 0, p, n, 1);
    printf("%d", maxlen);
}
void dfs(int n, int length, const pair<int, char> p[], const int &pNum, int stage)
{
    if (n == pNum)
    {
        if (length > maxlen)
        {
            maxlen = length;
        }
        return;
    }
    if (p[n].second == 'a')
    {
        if (stage != 2)
        {
            dfs(n + 1, length + p[n].first, p, pNum, stage);
        }
        else
        {
            dfs(n + 1, length + p[n].first, p, pNum, 3);
            dfs(n + 1, length, p, pNum, 2);
        }
    }
    else
    {
        if (stage == 1)
        {
            dfs(n + 1, length + p[n].first, p, pNum, 2);
            dfs(n + 1, length, p, pNum, 1);
        }
        else if (stage == 3)
        {
            dfs(n + 1, length, p, pNum, 3);
        }
        else
        {
            dfs(n + 1, length + p[n].first, p, pNum, 2);
        }
    }
    return;
}