#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int cmp(int a, int b)
{
    if (a < b)
        return 0;
    else
        return 1;
}
int main()
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + 4, cmp);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}