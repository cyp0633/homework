//有效的BFS Valid BFS | CF1037D
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
bool visited[200001];
vector<int> G[200001]; //图的邻接表
int main()
{
    int temp, tempFrom, tempTo, n, currPos, childNum;
    vector<int>::iterator it;
    queue<int> reqSeq, visitSeq; //请求访问顺序，实际访问顺序
    set<int> childSet;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &tempFrom, &tempTo);
        G[tempFrom].push_back(tempTo);
        G[tempTo].push_back(tempFrom);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        reqSeq.emplace(temp);
    }
    visitSeq.push(1);
    reqSeq.pop();
    while (!visitSeq.empty())
    {
        currPos = visitSeq.front();
        visitSeq.pop();
        if (visited[currPos])
        {
            continue;
        }
        visited[currPos] = true;
        for (it = G[currPos].begin(); it != G[currPos].end(); it++)
        {
            if (!visited[*it])
            {
                childSet.emplace(*it);
            }
        }
        childNum = childSet.size();
        for (int i = 0; i < childNum; i++)
        {
            set<int>::iterator it = childSet.find(reqSeq.front());
            if (it == childSet.end())
            {
                printf("No");
                return 0;
            }
            visitSeq.emplace(reqSeq.front());
            reqSeq.pop();
        }
        childSet.clear(); //清空儿子集合
    }
    printf("Yes");
    return 0;
}