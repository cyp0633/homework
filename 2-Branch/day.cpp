#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int y, m;
    bool r = false;
    scanf("%d%d", &y, &m);
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        r = true;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        printf("31");
    if (m == 4 || m == 6 || m == 9 || m == 11)
        printf("30");
    if (m == 2 && r)
        printf("29");
    if (m == 2 && !r)
        printf("28");
    return 0;
}