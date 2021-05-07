#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include "./grmat.h"
#include <iostream>
#include <queue>
#define UNVISITED 0
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
        printf("PreVisit vertex %d\n",start);
        G->setMark(start,VISITED);
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
                    G->setMark(i,VISITED);
                }
            }
            visitQueue.pop();
            PostVisit(temp);
        }
    }

    void Dijkstra1(int *D, int s)
    {
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
    }
};

#endif // GRAPH_TEST_H_INCLUDED
