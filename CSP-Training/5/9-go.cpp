//踩点上课 | CF1520G To Go Or Not To Go
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long int startToEndCost;
bool visited[2001][2001] = {false};
int map[2001][2001], n, m, w;
struct point
{
    int x, y;
    long long dist;
    point(const int currx, const int curry, const long long distance) : x(currx), y(curry), dist(distance) {}
    point() {}
};
long long bfs(const int &startX, const int &startY); //返回最近的传送门花费
int main()
{
    scanf("%d %d %d", &n, &m, &w);
    long long int startNearestCost, endNearestCost, portalCost;
    for (int i = 1; i <= n; i++) //坐标从1开始
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    if (map[1][1] == -1 || map[n][m] == -1)
    {
        printf("-1\n");
        return 0;
    }
    startToEndCost = startNearestCost = endNearestCost = INF;
    startNearestCost = bfs(1, 1);
    endNearestCost = bfs(n, m);
    portalCost = startNearestCost + endNearestCost;
    if (portalCost < startToEndCost)
    {
        printf("%lld\n", portalCost);
    }
    else
    {
        if (startToEndCost != INF)
        {
            printf("%lld", startToEndCost);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}
long long bfs(const int &startX, const int &startY)
{
    memset(visited, false, sizeof(visited));
    queue<point> visitQueue;
    point curr;
    long long minPortalCost, portalCost;
    minPortalCost = INF;
    visitQueue.emplace(point(startX, startY, 0)); //将起始点入队
    while (!visitQueue.empty())
    {
        point curr = visitQueue.front();
        visitQueue.pop();
        if (visited[curr.x][curr.y] || map[curr.x][curr.y] == -1) //访问过的或者不能走的，跳过
        {
            continue;
        }
        visited[curr.x][curr.y] = true;
        if ((curr.x == n && curr.y == m && startX == 1 && startY == 1) || (curr.x == 1 && curr.y == 1 && startX == n && startY == m)) //走完了全程
        {
            startToEndCost = curr.dist;
        }
        if (map[curr.x][curr.y] > 0) //这个格子是传送门
        {
            portalCost = curr.dist + map[curr.x][curr.y];
            minPortalCost = minPortalCost > portalCost ? portalCost : minPortalCost;
        }
        if (curr.x > 1) //x负
        {
            visitQueue.emplace(point(curr.x - 1, curr.y, curr.dist + w));
        }
        if (curr.x < n) //x正
        {
            visitQueue.emplace(point(curr.x + 1, curr.y, curr.dist + w));
        }
        if (curr.y > 1) //y负
        {
            visitQueue.emplace(point(curr.x, curr.y - 1, curr.dist + w));
        }
        if (curr.y < m) //y正
        {
            visitQueue.emplace(point(curr.x, curr.y + 1, curr.dist + w));
        }
    }
    return minPortalCost;
}