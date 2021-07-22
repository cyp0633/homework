//良心树 / CF1143C Queen
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool unrespectedByAll[100001], unrespectParent[100001];
int main()
{
    int n, parent, respect, i;
    bool printed = false;
    memset(unrespectedByAll, 1, sizeof(unrespectedByAll));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &parent, &respect);
        if (parent != -1)
        {
            unrespectedByAll[parent] &= respect;
            unrespectParent[i] = respect;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (unrespectParent[i] && unrespectedByAll[i])
        {
            printf("%d ", i);
            printed = true;
        }
    }
    if (!printed)
    {
        printf("-1");
    }
    return 0;
}