#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct work
{
    int num,score;
}w[3];
int swp(work a,work b);
int rnd(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5); 
}
int main()
{
    int salary, dist;
    char vacation;
    double x;
    for(int i=0;i<3;i++)
    {
        scanf("%d %c %d", &salary, &vacation, &dist);
        w[i].num=i;
        w[i].score+=rnd(1.0*salary/5000)*100;
		x=1.0*salary/5000;
        if(vacation=='y')w[i].score+=20;
        if(dist<=4000)w[i].score+=100;
        if(2000<=dist&&dist<=4000)w[i].score-=ceil((dist-2000)*1.0/200)*10;
    }
    sort(w,w+3,swp);
    printf("%c",w[0].num+'A');
    return 0;
}
int swp(work a,work b)
{
    if(a.score<=b.score)return false;
    else return true;
}