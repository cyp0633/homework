//Web导航
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> front, back;
    string curr = "http://www.game.org/", request;
    while (cin >> request)
    {
        if (request == "QUIT")
        {
            break;
        }
        else if (request == "BACK")
        {
            if (back.empty())
            {
                printf("Ignored\n");
                continue;
            }
            front.emplace(curr);
            curr = back.top();
            back.pop();
            cout << curr << '\n';
        }
        else if (request == "FORWARD")
        {
            if (front.empty())
            {
                printf("Ignored\n");
                continue;
            }
            back.emplace(curr);
            curr = front.top();
            front.pop();
            cout << curr << '\n';
        }
        else if (request == "VISIT")
        {
            while (!front.empty())
            {
                front.pop();
            }
            back.emplace(curr);
            cin >> curr;
            cout << curr << '\n';
        }
    }
    return 0;
}