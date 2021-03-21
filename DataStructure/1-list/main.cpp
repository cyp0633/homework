#include "linklist.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str1;
    LList<char> str;
    cin>>str1;
    int numcnt=0,charcnt=0,othercnt=0;
    for(string::iterator i=str1.begin();i!=str1.end();i++)
    {
        str.append((*i));
        if(*i>='0'&&*i<='9')
        {
            numcnt++;
        }
        else if((*i>='A'&&*i<='Z')||(*i>='a'&&*i<='z'))
        {
            charcnt++;
        }
        else
        {
            othercnt++;
        }
    }
    printf("%d %d %d\n",charcnt,numcnt,othercnt);
    for(string::iterator i=str1.begin();i!=str1.end();i++)
    {
        if(!(*i>='0'&&*i<='9'))
        {
            putchar(*i);
        }
    }
    return 0;
}