//选美大赛
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct participant
{
    int score, rank, num;
} p[100];
bool scoreComp(const participant &a, const participant &b);
bool numComp(const participant &a, const participant &b);
int main()
{
    int n, rankNum = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p[i].num = i + 1;
        scanf("%d", &p[i].score);
    }
    stable_sort(p, p + n, scoreComp);
    p[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i].score != p[i - 1].score)
        {
            rankNum++;
        }
        p[i].rank = rankNum;
    }
    sort(p, p + n, numComp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i].rank);
    }
    return 0;
}
bool scoreComp(const participant &a, const participant &b)
{
    return a.score > b.score;
}
bool numComp(const participant &a, const participant &b)
{
    return a.num < b.num;
}