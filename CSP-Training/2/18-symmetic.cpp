//小丑排序
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, set = 0;
    stack<string> s;
    string temp;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        set++;
        printf("set-%d\n", set);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (i % 2 == 0)
            {
                cout << temp << '\n';
            }
            else
            {
                s.emplace(temp);
            }
        }
        while (!s.empty())
        {
            cout << s.top() << '\n';
            s.pop();
        }
    }
    return 0;
}