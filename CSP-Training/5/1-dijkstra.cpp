//Dijkstra? CF20C
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int graph[10000][10000];
bool Greater(const string &a, const string &b);
int *Dijkstra(int source, int n)
{
    int *dist = new int[n + 1], mark[n + 1];
    string routeStr[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = 1 << 31 - 1;
        mark[i] = 0;
        routeStr[i] = "999999999";
    }
    routeStr[0] = "1";
    dist[source] = 0;
    int v;
    for (int i = 0; i < n; i++)
    {
        v = n;
        for (int j = 0; j < n; j++)
        {
            if (mark[j] == 0 && dist[j] < dist[v])
            {
                v = j;
            }
        }
        if (v == n)
        {
            break;
        }
        mark[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (((dist[j] == dist[v] + graph[v][j]) && Greater(routeStr[j], routeStr[v] + to_string(j + 1))) || dist[j] > dist[v] + graph[v][j])
            {
                dist[j] = dist[v] + graph[v][j];
                routeStr[j] = routeStr[v] + ' ' + to_string(j + 1);
            }
        }
    }
    if (dist[n - 1] == 1 << 31 - 1)
    {
        printf("-1");
        return dist;
    }
    cout << routeStr[n - 1];
    return dist;
}
int main()
{
    int n, m, s, source, dest, weight;
    scanf("%d %d", &n, &m);
    s = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 1 << 31 - 1;
        }
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &source, &dest, &weight);
        if (graph[source - 1][dest - 1] > weight)
        {
            graph[source - 1][dest - 1] = weight;
            graph[dest - 1][source - 1] = weight;
        }
    }
    int *dist = Dijkstra(s - 1, n);
    return 0;
}
bool Greater(const string &a, const string &b)
{
    int minLen = a.length() < b.length() ? a.length() : b.length();
    for (int i = 0; i < minLen; i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return false;
}