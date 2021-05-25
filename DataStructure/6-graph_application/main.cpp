#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include "grmat.h"
using namespace std;
int maxVertex(double* D,Graphm &g)
{
    int i,v=-1;
    for(i=0;i<g.n();i++)
    {
        if(g.getMark(i)==UNVISITED)
        {
            v=i;
            break;
        }
    }
    for(i++;i<g.n();i++)
    {
        if(g.getMark(i)==UNVISITED&&D[i]>D[v])
        {
            v=i;
        }
    }
    return v;
}
double ShortestPath(Graphm &g,int &source,int &dest)
{
    double *D=new double[g.n()];
    memset(D,0,g.n()*sizeof(double));
    D[source]=1;
    int v;
    for(int i=0;i<g.n();i++)
    {
        v=maxVertex(D,g);
        if(D[v]==0)
        {
            return 0;
        }
        g.setMark(v,VISITED);
        for(int w=g.first(v);w<g.n();w=g.next(v,w))
        {
            if(D[w]<D[v]*g.weight(v,w))
            {
                D[w]=D[v]*g.weight(v,w);
            }
        }
    }
    return D[dest];
}
int main()
{
    int m,n,source,dest,val,a,b;
    scanf("%d %d",&m,&n);
    Graphm g(m);
    for(int i=0;i<n;i++)
    {
        cin>>source>>dest>>val;
        g.setEdge(source-1,dest-1,1-(val/100.0));
        g.setEdge(dest-1,source-1,1-(val/100.0));//标号好像是从1开始的
    }
    scanf("%d %d",&a,&b);
    a-=1;
    b-=1;
    double ratio=ShortestPath(g,a,b);
    double num=100/ratio;
    printf("%lf",num);
    return 0;
}