#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int num[4],a,b,c;
    scanf("%lld %lld %lld %lld",&num[0],&num[1],&num[2],&num[3]);
    sort(num,num+4);
    a=num[3]-num[2];
    b=num[3]-num[1];
    c=num[3]-num[0];
    printf("%lld %lld %lld",a,b,c);
    return 0;
}