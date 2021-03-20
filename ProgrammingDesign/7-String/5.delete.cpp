//字符串左删除
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int minOperation = 2147483647;
void perform(string a, string b, int operation);
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    perform(a.substr(1), b, 1);
    perform(a, b.substr(1), 1);
    printf("%d", minOperation);
    return 0;
}
void perform(string a, string b, int operation)
{
    if (a == b)
    {
        if (operation < minOperation)
        {
            minOperation = operation;
        }
        return;
    }
    if (a.length() > 0)
    {
        perform(a.substr(1), b, operation + 1);
    }
    if (b.length() > 0)
    {
        perform(a, b.substr(1), operation + 1);
    }
    return;
}