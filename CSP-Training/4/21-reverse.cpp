//回文串
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
inline bool checkReverse(const string &str);
int main()
{
    string str, sub;
    int n, len, i;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        cin >> str;
        len = str.length();
        for (i = 0; i <= len; i++)
        {
            sub = str.substr(0, i);
            reverse(sub.begin(), sub.end());
            if (checkReverse(str + sub))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
inline bool checkReverse(const string &str)
{
    string::const_iterator i = str.begin();
    string::const_iterator j = str.end()-1;
    while (i < j)
    {
        if (*i != *j)
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}