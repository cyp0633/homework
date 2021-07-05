//能源消耗
#include <cstdio>
#include <iostream>
using namespace std;
int getConsumption(const int &p1, const int &p2, const int &p3, const int &t1, const int &t2, int duration);
int main()
{
    int n, p1, p2, p3, t1, t2, startTime, endTime = 0;
    long long sum = 0;
    scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
    scanf("%d %d", &startTime, &endTime);
    sum += (endTime - startTime) * p1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &startTime);
        sum += getConsumption(p1, p2, p3, t1, t2, startTime - endTime);
        scanf("%d", &endTime);
        sum += (endTime - startTime) * p1;
    }
    printf("%lld", sum);
    return 0;
}
int getConsumption(const int &p1, const int &p2, const int &p3, const int &t1, const int &t2, int duration)
{
    if (duration <= t1)
    {
        return p1 * duration;
    }
    int sum;
    sum = p1 * t1;
    duration -= t1;
    if (duration < t2)
    {
        sum += p2 * duration;
        return sum;
    }
    sum += p2 * t2;
    duration -= t2;
    sum += duration * p3;
    return sum;
}