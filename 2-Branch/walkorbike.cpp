#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    double tBike, tWalk;
    int dist;
    scanf("%d", &dist);
    tBike = 27 + 23 + dist / 3.0;
    tWalk = dist / 1.2;
    if (tBike > tWalk)
        printf("Walk");
    if (tBike == tWalk)
        printf("All");
    if (tBike < tWalk)
        printf("Bike");
    return 0;
}