//字符串反转2
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    stack<string> words;
    while (cin >> str)
    {
        words.emplace(str);
        if (cin.peek() == '\n' || cin.peek() == EOF)
        {
            while (!words.empty())
            {
                cout << words.top();
                words.pop();
                if (!words.empty())
                    putchar(' ');
            }
            cout << endl;
        }
    }
    return 0;
}