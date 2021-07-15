//挖掘机技术哪家强
#include <cstdio>
#include <iostream>
using namespace std;
int score[100000];
int main()
{
    int maxScoreSchool = 0, tempSchool, tempScore, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tempSchool, &tempScore);
        score[tempSchool] += tempScore;
        if (score[tempSchool] > score[maxScoreSchool])
        {
            maxScoreSchool = tempSchool;
        }
    }
    printf("%d %d", maxScoreSchool, score[maxScoreSchool]);
}