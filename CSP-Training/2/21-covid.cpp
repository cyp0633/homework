//新型冠状病毒（COVID19）传播
#include <cstdio>
#include <iostream>
using namespace std;
int pos[10000000], speed[10000000];
bool infected[10000000];
int checkInfection(const int &sourcePos, const int &sourceSpeed, const int &targetPos, const int &targetSpeed);
int main()
{
    int n, count = 0, k, maxK, minK;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &speed[i]);
    }
    maxK = minK = k - 1;
    infected[k - 1] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == k - 1)
        {
            continue;
        }
        if (checkInfection(pos[k - 1], speed[k - 1], pos[i], speed[i]) == 0)
        {
            infected[i] = true;
            if (speed[i] > speed[maxK])
            {
                maxK = i;
            }
            if (speed[i] < speed[minK])
            {
                minK = i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (infected[i])
        {
            count++;
            continue;
        }
        if (checkInfection(pos[maxK], speed[maxK], pos[i], speed[i]) < 1 && checkInfection(pos[minK], speed[minK], pos[i], speed[i]) > -1)
        {
            count++;
        }
    }
    printf("%d", count);
}
int checkInfection(const int &sourcePos, const int &sourceSpeed, const int &targetPos, const int &targetSpeed) //返回值：1 - 在上方 0 - 相交 -1 - 在下方
{
    if ((sourcePos > targetPos && sourceSpeed < targetSpeed) || (sourcePos < targetPos && sourceSpeed > targetSpeed) || (sourcePos == targetPos))
    {
        return 0;
    }
    if ((targetPos > sourcePos) && (targetSpeed >= sourceSpeed))
    {
        return 1;
    }
    return -1;
}