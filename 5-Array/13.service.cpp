//小希的新工作
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int ti, li, n, lastEnd = 0, i, j, l, a, count = 0;
    scanf("%d %d %d", &n, &l, &a);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &ti, &li);
        count += (ti - lastEnd) / a;
        lastEnd = ti + li;
    }
    count += (l - lastEnd) / a;
    printf("%d", count);
}