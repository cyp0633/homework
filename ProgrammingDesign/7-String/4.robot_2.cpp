//机器人游戏
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
void perform();
int main()
{
    int t,i;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        perform();
    }
    return 0;
}
void perform()
{
    string s;
    int len,i,j,n=0;
    getline(cin,s);
    len=s.length();
    pair<int,int> robot[1000];//first 初始位置，second 移动距离
    for(i=0;i<len;i++)
    {
        if(s[i]!='.')
        {
            robot[n].first=i;
            robot[n].second=s[i]-'0';
            n++;
        }
    }
    if(n<=1)
    {
        printf("safe\n");
        return;
    }
    for(i=0;i<n-1;i++)
    {
        if(robot[i+1].second+robot[i].second>=robot[i+1].first-robot[i].first)
        {
            printf("unsafe\n");
            return;
        }
    }
    printf("safe\n");
    return;
}