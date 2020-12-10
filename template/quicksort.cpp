//快速排序
#include<cstdio>
#include<iostream>
using namespace std;
void quicksort(int num[],int l,int r);
void swap(int* a,int* b);
int main()
{
    int num[100000],n,a;
    scanf("%d",&n);
    for(a=0;a<n;a++)
    {
        scanf("%d",&num[a]);
    }
    quicksort(num,0,n-1);
    for(a=0;a<n;a++)
    {
        printf("%d ",num[a]);
    }
    return 0;
}
void quicksort(int num[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int i,j,pivot=*(num+l);
    i=l;
    j=r;
    while(i<j)
    {
        while(*(num+j)>=pivot&&i<j)
        {
            j--;
        }
        while(*(num+i)<=pivot&&i<j)
        {
            i++;
        }
        if(i<j)swap(num+i,num+j);
    }
    swap(num+l,num+i);
    quicksort(num,l,i-1);
    quicksort(num,i+1,r);
    return;
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}