//最昂贵的旅行
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dijkstra(int n);
int map[100][100]; //编号0~n-1
int main()
{
    int n, source, dest, cost;
    scanf("%d", &n);
    memset(map, 0x7f, sizeof(map));
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &source, &dest, &cost);
        map[source][dest] = cost;
        map[dest][source] = cost;
    }
    cout << dijkstra(n);
    return 0;
}
int dijkstra(int n) //Source=0
{
    bool visited[101];
    int dist[101], maxDist = -1;
    memset(visited, false, sizeof(visited));
    memset(dist, 0x7f, sizeof(dist));
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = 100;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && dist[j] < dist[u])
            {
                u = j;
            }
        }
        if (u == 100)
        {
            break;
        }
        visited[u] = true;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && dist[j] > map[u][j] + dist[u])
            {
                dist[j] = map[u][j] + dist[u];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
        }
    }
    return maxDist;
}