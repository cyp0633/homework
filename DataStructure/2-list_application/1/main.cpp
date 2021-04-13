#include "./linklist.h"
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str1;
    LList<char> str;
    cin >> str1;
    for (string::iterator i = str1.begin(); i != str1.end(); i++)
    {
        str.append(*i);
    }
    stack<char> charStack;
    char temp;
    str.moveToStart();
    int i;
    for (i = 0; i < str.length() / 2; i++)
    {
        temp = str.getValue();
        charStack.push(temp);
        str.next();
    }
    if (str.length() % 2 == 1)
    {
        str.next();
        i++;
    }
    for (; i < str.length(); i++)
    {
        temp = str.getValue();
        if (temp != charStack.top())
        {
            printf("no");
            return 0;
        }
        else
        {
            charStack.pop();
            str.next();
        }
    }
    printf("yes");
    return 0;
}