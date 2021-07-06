//合法的括号串
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool ifLeftBracket(const char &c);
bool ifRightBracket(const char &c);
char transform(const char &c);
int main()
{
    int T;
    string str;
    stack<char> s;
    cin >> T;
    for (; T > 0; T--)
    {
        cin >> str;
        for (string::iterator i = str.begin(); i != str.end(); i++)
        {
            if (ifLeftBracket(*i))
            {
                s.emplace(*i);
            }
            if (ifRightBracket(*i))
            {
                if (s.empty())
                {
                    goto loopEnd;
                }
                if (transform(*i) == s.top())
                {
                    s.pop();
                }
                else
                {
                    goto loopEnd;
                }
            }
        }
        if (s.empty())
        {
            printf("Yes\n");
        }
        else
        {
        loopEnd:
            printf("No\n");
            while (!s.empty()) //栈一定要清空，否则前面有不匹配的数据的话，会有残留导致最后不为空
            {
                s.pop();
            }
        }
    }
    return 0;
}
bool ifLeftBracket(const char &c)
{
    if (c == '<' || c == '(' || c == '[' || c == '{')
    {
        return true;
    }
    return false;
}
char transform(const char &c)
{
    if (c == '>')
    {
        return '<';
    }
    if (c == ')')
    {
        return '(';
    }
    if (c == ']')
    {
        return '[';
    }
    if (c == '}')
    {
        return '{';
    }
    return ' ';
}
bool ifRightBracket(const char &c)
{
    if (c == ')' || c == ']' || c == '}' || c == '>')
    {
        return true;
    }
    return false;
}