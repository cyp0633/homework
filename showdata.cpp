#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    //freopen("listin.txt","r",stdin);
    //freopen("listout.txt","w",stdout);
    string a;
    while(getline(cin,a))
    {
        cout<<a<<'\n';
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}