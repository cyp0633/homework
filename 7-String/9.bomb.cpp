//炸弹💣
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool check(char field[1000][1000],int n,int m,int x,int y);
void perform();
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        perform();
    }
    return 0;
}
bool check(char field[1000][1000],int n,int m,int x,int y)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        field[i][x]='.';
    }
    for(i=0;i<m;i++)
    {
        field[y][i]='.';
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(field[j][i]=='*')
            {
                return false;
            }
        }
    }
    return true;
}
void perform()
{
    char field[1000][1000];
    int m,n,i,j,x,y;//n是行，m是列
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++)
    {
        gets(field[i]);
    }
    for(i=0;i<m;i++)//列 枚举炸弹放置位置
    {
        for(j=0;j<n;j++)//行
        {
            if(check(field,n,m,i,j))
            {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
    return;
}