#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    double x;
    scanf("%lf",&x);
    if(x<=-1)printf("%.6lf",x-1);
    else if(x<=2)printf("%.6lf",x*2);
    else printf("%.6lf",(x*x+x*2));
    return 0;
}