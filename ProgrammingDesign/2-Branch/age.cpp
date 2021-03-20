#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct person
{
    int y, m, d;
    char s;
} p[3];
int cmp(person a, person b)
{
    if (a.y > b.y)
        return 0;
    if (a.y == b.y && a.m > b.m)
        return 0;
    if (a.y == b.y && a.m == b.m && a.d > b.d)
        return 0;
    return 1;
}
int main()
{
    int t;
    for (t = 0; t < 3; t++)
    {
        p[t].s = 'A' + t;
        scanf("%d %d %d", &p[t].y, &p[t].m, &p[t].d);
    }
    sort(p, p + 3, cmp);
    printf("%c%c%c", p[0].s, p[1].s, p[2].s);
    return 0;
}