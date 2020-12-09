#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int inTime[1000];
int main()
{
    int n,m,a,d,i,j,count=0,closeTime=0;
    bool door=false;
    scanf("%d %d %d %d",&n,&m,&a,&d);
    for(i=0;i<m;i++)
    {
        scanf("%d",&inTime[i]);
    }
    for(j=m;j<m+n;j++)
    {
        inTime[j]=(j-m+1)*a;
    }
    sort(inTime,inTime+n+m);
    for(i=0;i<inTime[m+n-1];i++)
    {
        if(!door)
        {
            door=true;
            count++;
            closeTime=inTime[i]+d;
        }
        if(inTime[i+1]>closeTime)
        {
            door=false;
            closeTime=inTime[i+1];
        }
    }
    if(inTime[m+n-1]>closeTime)
    {
        count++;
    }
    printf("%d",count);
    return 0;
}