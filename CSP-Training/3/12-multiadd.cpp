//多项式加法
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> a;
    int coefficient,num;
    while(cin>>num>>coefficient)
    {
        if(num==coefficient&&num==0)
        {
            break;
        }
        if(a.count(num)==0)
        {
            a[num]=coefficient;
        }
        else
        {
            a[num]+=coefficient;
        }
    }
    while(cin>>num>>coefficient)
    {
        if(num==coefficient&&num==0)
        {
            break;
        }
        if(a.count(num)==0)
        {
            a[num]=coefficient;
        }
        else
        {
            a[num]+=coefficient;
        }
    }
    for(map<int,int>::reverse_iterator i=a.rbegin();i!=a.rend();i++)
    {
        if(i->second==0)
        {
            continue;
        }
        else
        {
            printf("%d %d\n",i->first,i->second);
        }
    }
    return 0;
}