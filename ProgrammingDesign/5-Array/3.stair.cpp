#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n,i,count=0;
    scanf("%d",&n);
    int num[1000]={0};
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]==1)
        {
            count++;
        }
    }
    printf("%d\n",count);
    for(i=1;i<=n;i++)
    {
        if(num[i]==1&&i!=1)
        {
            printf("%d ",num[i-1]);
        }
    }
    printf("%d",num[n]);
    return 0;
}