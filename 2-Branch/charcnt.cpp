#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n,t,num=0,other=0,cap=0,low=0,sum=0;
    char c;
    scanf("%d\n",&n);
    for(t=0;t<n;t++)
    {
        if(t!=n-1)scanf("%c\n",&c);
        else scanf("%c",&c);
        if('0'<=c&&c<='9')
        {
            num++;
            sum+=c-'0';
        }
        else if('a'<=c&&c<='z') low++;
        else if('A'<=c&&c<='Z') cap++;
        else other++;
    }
    printf("%d %d %d %d",cap,low,num,other);
    if(sum)printf("\n%d",sum);
    return 0;
}