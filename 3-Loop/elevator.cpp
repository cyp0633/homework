//19 电梯
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, req, prevFloor = 0, t, sum = 0;
    scanf("%d", &n);
    for (t = 0; t < n; t++)
    {
        scanf("%d", &req);
        sum += 5;
        if (req > prevFloor)
        {
            sum += 6 * (req - prevFloor);
        }
        if (req < prevFloor)
        {
            sum += 4 * (prevFloor - req);
        }
        prevFloor = req;
    }
    printf("%d", sum);
    return 0;
}