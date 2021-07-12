//部分A+B
#include<cstdio>
#include<iostream>
using namespace std;
long long int getPart(const string &s,const int &n);
int main()
{
    string a,b;
    int da,db;
    long long pa,pb;
    cin>>a>>da>>b>>db;
    pa=getPart(a,da);
    pb=getPart(b,db);
    printf("%lld",pa+pb);
    return 0;
}
long long int getPart(const string &s,const int &n)
{
    int count=0;
    long long int p=0;
    for(string::const_iterator i=s.begin();i!=s.end();i++)
    {
        if(*i==n+'0')
        {
            count++;
        }
    }
    for(int i=0;i<count;i++)
    {
        p*=10;
        p+=n;
    }
    return p;
}