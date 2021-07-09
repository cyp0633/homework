//绩点计算
#include <cstdio>
#include <iostream>
using namespace std;
double getGPA(const int &score);
int main()
{
    double sumGPA = 0;
    pair<int, int> course[1000];
    int n, sumPoint = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &course[i].first);
        sumPoint += course[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &course[i].second);
        sumGPA += course[i].first * getGPA(course[i].second);
    }
    sumGPA /= sumPoint;
    printf("%.2lf", sumGPA);
    return 0;
}
double getGPA(const int &score)
{
    if (score >= 90)
    {
        return 4.0;
    }
    if (score >= 85)
    {
        return 3.7;
    }
    if (score >= 82)
    {
        return 3.3;
    }
    if (score >= 78)
    {
        return 3.0;
    }
    if (score >= 75)
    {
        return 2.7;
    }
    if (score >= 72)
    {
        return 2.3;
    }
    if (score >= 68)
    {
        return 2.0;
    }
    if (score >= 64)
    {
        return 1.5;
    }
    if (score >= 60)
    {
        return 1.0;
    }
    return 0.0;
}