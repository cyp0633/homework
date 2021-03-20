//基于神经网络的垃圾分类
#include<cstdio>
#include<iostream>
using namespace std;
void perform();
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        perform();
    }
    return 0;
}
void perform()
{
    int n,i,j,w,b;
    bool wB[10000],result,bB[10000];
    long long int countYes=0,countNo=0,minX,maxX;
    scanf("%d %d %d",&n,&minX,&maxX);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&w,&b);
        if(w%2)//规定奇数为1，偶数为0
        {
            wB[i]=1;
        }
        else
        {
            wB[i]=0;
        }
        if(b%2)
        {
            bB[i]=1;
        }
        else
        {
            bB[i]=0;
        }
    }
    for(i=minX;i<=maxX;i++)
    {
        if(i%2)
        {
            result=1;
        }
        else
        {
            result=0;
        }
        for(j=0;j<n;j++)
        {
            if((result&&bB[j])||(!result&&!bB[j])||(result&&!wB[j]&&!bB[j])||(!result&&wB[j]&&bB[j]))//偶的情况
            {
                result=0;
            }
            else
            {
                result=1;
            }
        }
        if(result)
        {
            countYes++;
        }
        else
        {
            countNo++;
        }
    }
    printf("%d %d\n",countNo,countYes);
    return;
}