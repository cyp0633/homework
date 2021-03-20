#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    double c,f;
    cin>>f;
    c=5*(f-32)/9;
    cout<<fixed<<setprecision(5)<<c<<endl;
}