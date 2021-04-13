//实验二b 利用STL实现括号匹配
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
bool checkPair(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '<' && b == '>') || (a == '{' && b == '}'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    stack<char> brackets;
    cin >> str;
    for (string::iterator j = str.begin(); j != str.end(); j++)
    {
        if (*j == '{' || *j == '[' || *j == '(' || *j == '<')
        {
            brackets.emplace(*j);
        }
        else
        {
            if (brackets.empty() || !checkPair(brackets.top(), *j))
            {
                printf("no\n");
                return 0;
            }
            else
            {
                brackets.pop();
            }
        }
    }
    if (brackets.empty())
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}