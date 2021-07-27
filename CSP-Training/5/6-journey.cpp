//CF893C Journey
#include <cstdio>
#include <iostream>
using namespace std;
bool visited[100001];
int head[100001], nxt[200000], to[200000], n, sons[100001];
double expectation;
void dfs(int currentPos, double possibility, int depth);
void insert(int source, int dest, int i);
int main()
{
    scanf("%d", &n);
    int tempSource, tempDest;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &tempSource, &tempDest);
        insert(tempSource, tempDest, i * 2 + 1);
        insert(tempDest, tempSource, i * 2 + 2);
    }
    sons[1] /= 2;
    for (int i = 2; i <= n; i++) //除根节点外，子节点数=连接边数-1
    {
        sons[i] = sons[i] / 2 - 1;
    }
    dfs(1, 1.0, 0);
    printf("%.7lf\n", expectation); //HNU CG强制要求7位小数，不然不过
}
void dfs(int currentPos, double possibility, int depth)
{
    if (visited[currentPos])
    {
        return;
    }
    if (sons[currentPos] == 0)
    {
        expectation += possibility * depth;
        return;
    }
    visited[currentPos] = true;
    double sonPossibility = possibility / sons[currentPos];
    for (int i = head[currentPos]; i != 0; i = nxt[i])
    {
        dfs(to[i], sonPossibility, depth + 1);
    }
}
void insert(int source, int dest, int i)
{
    nxt[i] = head[source];
    to[i] = dest;
    head[source] = i;
    sons[source]++;
    sons[dest]++;
}