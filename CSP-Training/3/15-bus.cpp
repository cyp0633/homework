//公交系统
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int change, count = 0, capacity, n, maxNum = 0, minNum = 0;
    scanf("%d %d", &n, &capacity);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &change);
        count += change;
        maxNum = maxNum > count ? maxNum : count;
        minNum = minNum < count ? minNum : count;
    }
    if (minNum * -1 > capacity || maxNum > capacity)
    {
        printf("0");
        return 0;
    }
    printf("%d", capacity - maxNum + 1 + minNum);
}