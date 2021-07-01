#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string str;
    stack<string> words;
    while(cin>>str)
    {
        words.emplace(str);
        if(cin.peek()=='\n')
        {
            while(!words.empty())
            {
                cout<<words.top()<<' ';
                words.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}