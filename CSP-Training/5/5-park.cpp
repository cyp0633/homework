//猫与餐厅的故事 Kefa and Park
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool isCat[100001], visited[100001];
int head[100001], nxt[100000 * 2], to[100000 * 2], n, m, count;
void dfs(int currentPos, int currConsecutiveCat);
void insert(int source, int dest, int i);
int main()
{
    int temp1, temp2;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp1);
        isCat[i] = (int)temp1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        insert(temp1, temp2, i * 2 - 1);
        insert(temp2, temp1, i * 2);
    }
    dfs(1, isCat[1]);
    printf("%d\n", count);
    return 0;
}
void dfs(int currentPos, int currConsecutiveCat) //当前访问结点下标，当前连续猫数，最大连续猫数
{
    if (currConsecutiveCat > m || visited[currentPos]) //猫太多或者已经访问过
    {
        return;
    }
    visited[currentPos] = true;                        //标记结点已访问过
    if (nxt[head[currentPos]] == 0 && currentPos != 1) //是叶子结点，头的下一个就没有了
    {
        count++;
        return;
    }
    for (int i = head[currentPos]; i != 0; i = nxt[i])
    {
        if (isCat[to[i]])
        {
            dfs(to[i], currConsecutiveCat + 1);
        }
        else
        {
            dfs(to[i], 0);
        }
    }
}
void insert(int source, int dest, int i)
{
    nxt[i] = head[source];
    head[source] = i;
    to[i] = dest;
}