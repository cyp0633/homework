//松雅的旅馆
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n, d, pos[1000], minDist, i, j, count = 0;
    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pos[i]);
    }
    for (i = pos[0] + 1; i < pos[n - 1]; i++)
    {
        minDist = 1 << 30;
        for (j = 0; j < n; j++)
        {
            if (abs(pos[j] - i) < minDist)
            {
                minDist = abs(pos[j] - i);
            }
            if (i == pos[j] || minDist < d)
            {
                minDist = -1;
                break;
            }
        }
        if (minDist == d)
        {
            count++;
        }
    }
    count += 2;
    printf("%d", count);
}