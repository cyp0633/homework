//看电影 CodeForces 670C弱化版
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct film
{
    int veryHappy;  //音频
    int happyCount; //字幕
    int num;
} f[200000];
bool comp(film a, film b);
int main()
{
    int i, j, n, m, audioLang, subsLang, profLang;
    int langCount[1000] = {0};
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> profLang;
        langCount[profLang]++;
    }
    cin >> m;
    for (i = 0; i < m; i++) //音频语言
    {
        cin >> audioLang;
        f[i].num = i + 1;
        f[i].veryHappy = langCount[audioLang];
    }
    for (j = 0; j < m; j++)
    {
        cin >> subsLang;
        f[i].happyCount = langCount[subsLang];
    }
    sort(f, f + m, comp);
    if (f[0].happyCount == 0 && f[0].veryHappy == 0)
    {
        cout << "unsatisfied";
        return 0;
    }
    for (i = 0; i < m; i++)
    {
        if (f[i].veryHappy == f[0].veryHappy && f[i].happyCount == f[0].happyCount)
        {
            cout << f[i].num << ' ';
        }
    }
    return 0;
}
bool comp(film a, film b)
{
    if (a.veryHappy != b.veryHappy)
    {
        return a.veryHappy > b.veryHappy;
    }
    if (a.happyCount != b.happyCount)
    {
        return a.happyCount > b.happyCount;
    }
    return a.num < b.num;
}