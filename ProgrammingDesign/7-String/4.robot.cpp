//机器人游戏
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
struct robot
{
    int originalPos;
    int moveDist;
    int serial;
};
stack<robot> bot;
int m[1000];
void search();
int main()
{
    int t,i,j,m,n,len,count;
    string space;
    robot b;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        count=0;
        stack<robot>().swap(bot);//清空bot栈
        getline(cin,space);
        len=space.length();
        for(j=0;j<len;j++)
        {
            if(space[j]!='.')
            {
                count++;
                b.originalPos=j;
                b.serial=count;
                b.moveDist=space[j]-'0';
            }
        }
        
    }
}