//树的优化 | CF682C Alyona and the Tree
#include <cstdio>
#include <iostream>
using namespace std;
int head[100001], nxt[100000], to[100000], val[100001], weight[100000];
int n, preserveCount;
void dfs(int currPos, int dist);
void insert(const int &source, const int &dest, const int &wt);
int main()
{
    int parentTemp, weightTemp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i < n; i++) //从第2号结点开始输入父节点和边权
    {
        scanf("%d %d", &parentTemp, &weightTemp);
        insert(parentTemp, i + 1, weightTemp); //只需要加一条，这个是有向的
    }
    dfs(1, 0);
    printf("%d", n - preserveCount);
    return 0;
}
void dfs(int currPos, int dist)
{
    if (dist > val[currPos])
    {
        return;
    }
    preserveCount++;
    for (int i = head[currPos]; i != 0; i = nxt[i])
    {
        if (dist > 0)
        {
            dfs(to[i], dist + weight[i]);
        }
        else
        {
            dfs(to[i], weight[i]);
        }
    }
    return;
}
void insert(const int &source, const int &dest, const int &wt)
{
    nxt[dest - 1] = head[source];
    head[source] = dest - 1;
    to[dest - 1] = dest;
    weight[dest - 1] = wt;
}