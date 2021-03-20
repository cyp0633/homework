//22莫比乌斯函数
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int ss(int x);
void check(int x,int count,int last);
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)//特判1
    {
        printf("1");
        return 0;
    }
    if(n%4==0||n%9==0)//特判4或9为因子，肯定是存在平方因子
    {
        printf("0");
        return 0;
    }
    if(ss(n)==0)//特判素数……有必要么？
    {
        printf("-1");
        return 0;
    }
    check(n,0,1);
    return 0;
}
void check(int x,int count,int last)
{
    int a=ss(x);
    if(a==last||last==x)
    {
        printf("0");
        return;
    }
    if(a==0)
    {
        if(count%2==1)
        {
            printf("-1");
            return;
        }
        else
        {
            printf("1");
        }
    }
    else
    {
        check(x/a,count+1,a);
    }
    return;
}
int ss(int x)
{
    int y,t=sqrt(x);
    for(y=2;y<=t;y++)
    {
        if(x%y==0)
        {
            return y;
        }
    }
    return 0;
}