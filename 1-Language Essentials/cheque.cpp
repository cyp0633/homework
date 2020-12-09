#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    float price=0;
    int code=0;
    scanf("%d %f",&code,&price);
    cout<<setfill('0');
    cout<<setw(8)<<code<<endl;
    printf("%.2f",price);
    //printf("%8d\n%.2f",code,price);
    return 0;
}