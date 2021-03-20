//最大公约数和最小公倍数
#include<iostream>
using namespace std;
int lcm(int u,int v);
int gcd(int u,int v);
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d %d",gcd(x,y),lcm(x,y));
    return 0;
}
int gcd(int u,int v)
{
    if(u<v)
    {
        int i=v;
        v=u;
        u=i;
    }
    return v==0?u:gcd(v,u%v);
}
int lcm(int u,int v)
{
    return u*v/gcd(u,v);
}