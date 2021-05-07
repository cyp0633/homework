#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>
#include "./graph.h"
#include <iostream>
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
    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
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
