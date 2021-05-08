#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include "./grmat.h"
#include <cstdio>
#include <iostream>
#include <queue>
#define UNVISITED 0
using namespace std;
class option
{
private:
    Graph *G;

public:
    // Start with some implementations for the abstract functions
    option(Graph *g)
    {
        G = g;
    }

    void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v)) // Depth first search
    {
        if (G->getMark(v) == VISITED)
        {
            return;
        }
        PreVisit(v); //不知道这个位置对不对
        Visiting(v);
        G->setMark(v, VISITED);
        for (int i = 0; i < G->n(); i++)
        {
            if (G->isEdge(v, i))
            {

                DFS(i, PreVisit, PostVisit, Visiting);
            }
        }
        PostVisit(v);
    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
        std::queue<int> visitQueue;
        visitQueue.emplace(start);
        int temp;
        printf("PreVisit vertex %d\n", start);
        G->setMark(start, VISITED);
        while (!visitQueue.empty())
        {
            temp = visitQueue.front();
            Visiting(temp);
            for (int i = 0; i < G->n(); i++)
            {
                if (G->isEdge(temp, i) && !G->getMark(i))
                {
                    PreVisit(i);
                    visitQueue.push(i);
                    G->setMark(i, VISITED);
                }
            }
            visitQueue.pop();
            PostVisit(temp);
        }
    }

    void Dijkstra1(int *D, int s) //D是距离数组，s是起始点
    {
        // priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int, int>>> dist; //优先队列写佛了，写个暴力的
        // dist.push(pair<int, int>(0, s));//first是距离，second是终点
        // while(!dist.empty())
        // {
        //     pair<int,int> temp=dist.top();
        //     D[temp.second]=temp.first;
        //     dist.pop();
        //     for(int i=0;i<G->n();i++)
        //     {
        //         if(G->isEdge(temp.second,i)&&temp.first+G->weight(temp.second,i)<D[i])
        //         {
        //             D[i]=temp.first+G->weight(temp.second,i);
        //             dist.push(pair<int,int>(D[i],i));
        //         }
        //     }
        // }
        int v;
        for(int i=0;i<G->n();i++)
        {
            v=minVertex(D);
            if(D[v]==INFINITY)
            {
                return;
            }
            G->setMark(v,VISITED);
            for(int w=G->first(v);w<G->n();w=G->next(v,w))
            {
                if(D[w]>D[v]+G->weight(v,w))
                {
                    D[w]=D[v]+G->weight(v,w);
                }
            }
        }
    }

    int minVertex(int *D) // Find min cost vertex
    {
        int i, v = -1;
        // Initialize v to some unvisited vertex
        for (i = 0; i < G->n(); i++)
            if (G->getMark(i) == UNVISITED)
            {
                v = i;
                break;
            }
        for (i++; i < G->n(); i++) // Now find smallest D value
            if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
                v = i;
        return v;
    }

    void AddEdgetoMST(int v1, int v2)
    {
        std::cout << "Add edge " << v1 << " to " << v2 << "\n";
    }
    void Prim(int *D, int s) // Prim's MST algorithm
    {
        int nearNeighbor[G->n()];
        for(int i=0;i<G->n();i++)
        {
            int v=minVertex(D);
            G->setMark(v,VISITED);
            if(v!=s)
            {
                AddEdgetoMST(nearNeighbor[v],v);
            }
            if(D[v]==INFINITY)
            {
                return;
            }
            for(int w=G->first(v);w<G->n();w=G->next(v,w))
            {
                if(D[w]>G->weight(v,w))
                {
                    D[w]=G->weight(v,w);
                    nearNeighbor[w]=v;
                }
            }
        }
    }
};

#endif // GRAPH_TEST_H_INCLUDED
