//小希与火车
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int count,t,m,n,v,l,r,tl;
    scanf("%d",&t);
    for(m=0;m<t;m++)
    {
        count=0;
        scanf("%d %d %d %d",&tl,&v,&l,&r);
        for(n=1;n*v<=tl;n++)
        {
            if(n*v>=l&&n*v<=r)
            {
                continue;
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}