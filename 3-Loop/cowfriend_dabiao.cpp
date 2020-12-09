//牛友（打表器） USACO 2011?
#include <cstdio>
#include <iostream>
using namespace std;
int ysh(int x);
int main()
{
    int ny[15] = {220, 284, 1184, 1210, 2620, 2924, 5020, 5564, 6232, 6368, 10744, 10856, 12285, 14595, 17296};
    int ny2[15] = {284, 220, 1210, 1184, 2924, 2620, 5564, 5020, 6368, 6232, 10856, 10744, 14595, 12285, 18416};
    int s, i;
    scanf("%d", &s);
    for (i = 0; i < 15; i++)
    {
        if (ny[i] >= s)
        {
            printf("%d %d", ny[i], ny2[i]);
            return 0;
        }
    }
}