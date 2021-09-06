//数塔
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int tower[1000][1000], n, maxDist;
vector<int> maxRoute;
void dfs(int layer, int num, int dist, vector<int> route);
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &tower[i][j]);
        }
    }
    dfs(0, 0, 0, vector<int>(0));
    printf("%d\n", maxDist);
    for (vector<int>::iterator i = maxRoute.begin(); i != maxRoute.end(); i++)
    {
        printf("%d ", *i);
    }
    return 0;
}
void dfs(int layer, int num, int dist, vector<int> route)
{
    dist += tower[layer][num];
    route.push_back(tower[layer][num]);
    if (layer == n - 1)
    {
        if (dist > maxDist)
        {
            maxDist = dist;
            maxRoute = route;
        }
        return;
    }
    dfs(layer + 1, num, dist, route);
    dfs(layer + 1, num + 1, dist, route);
}