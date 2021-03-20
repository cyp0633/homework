#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    char a,b,c[10];
    int i,j;
    cin>>a>>b;
    for(i=0;i<10;i++)
    {
        cin>>c[i];
    }
    for(i=0;i<10;i+=2)//判断点数
    {
        if(c[i]==a)
        {
            cout<<"YES";
            return 0;
        }
    }
    for(i=1;i<10;i+=2)//判断花色
    {
        if(c[i]==b)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}