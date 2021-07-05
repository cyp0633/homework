//字符串反转3
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int N, count;
    string s;
    cin >> N;
    while (N--)
    {
        while (cin >> s)
        {
            // reverse(s.begin(), s.end());
            // cout << s << ' ';
            for (int i = s.length() - 1; i >= 0; i--)
            {
                cout << s[i];
            }
            cout<<' ';
            if (cin.peek() == '\n')
            {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}