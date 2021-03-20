//猴导师
#include <cstdio>
#include <iostream>
using namespace std;
bool conflict[10000][10000];
int ability[10000];
int main()
{
    int count, i, j, n, k, a, b;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ability[i]);
    }
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        conflict[a - 1][b - 1] = true;
        conflict[b - 1][a - 1] = true;
    }
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (conflict[i][j])
            {
                continue;
            }
            if (ability[i] > ability[j])
            {
                count++;
            }
        }
        printf("%d ", count);
    }
    return 0;
}