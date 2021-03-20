//选举
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int candidate[100], vote, maxCity;
    memset(candidate, 0, 100);
    int n, m, i, j, maxVote, maxNum;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        maxVote = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &vote);
            if (vote > maxVote)
            {
                maxVote = vote;
                maxCity = j;
            }
        }
        candidate[maxCity]++;
    }
    maxVote = 0;
    for (i = 0; i < n; i++)
    {
        if (candidate[i] > maxVote)
        {
            maxVote = candidate[i];
            maxNum = i + 1;
        }
    }
    printf("%d", maxNum);
}