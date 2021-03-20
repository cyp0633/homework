//快速公交
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n,g,r,q,i,j,period,deptTime,arrvTime=0;
    scanf("%d%d%d",&n,&g,&r);
    int passTime[n+1],totalPass=0;
    for(i=0;i<=n;i++)
    {
        scanf("%d",&passTime[i]);
        totalPass+=passTime[i];
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&deptTime);
        arrvTime=deptTime+passTime[0];
        for(j=0;j<n;j++)
        {
            period=arrvTime%(g+r);
            if(period>=g)
            {
                arrvTime+=r+g-period;
            }
            arrvTime+=passTime[j+1];
        }
        printf("%d ",arrvTime);
    }
    return 0;
}