//16 阿迪玩游戏
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int i,x,y,n,m,step,sum=0,period;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&step);
        sum+=step;
    }
    period=2*(n-1);
    sum%=period;
    if(sum<=n-1)
    {
        x=sum+1;
        printf("%d",x);
    }
    else
    {
        x=2*n-sum-1;
        printf("%d",x);
    }
    return 0;
}