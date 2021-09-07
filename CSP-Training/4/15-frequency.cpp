//字频统计
#include <cstdio>
#include <iostream>
using namespace std;
size_t findab(const string &str, const int &startPos);
size_t findba(const string &str, const int &startPos);
int main()
{
    string str;
    int n, ab, ba;
    size_t pos;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        ab = ba = 0;
        cin >> str;
        pos = findab(str, 0);
        while (pos != string::npos)
        {
            ab++;
            pos = findab(str, pos + 1);
        }
        pos = findba(str, 0);
        while (pos != string::npos)
        {
            ba++;
            pos = findba(str, pos + 1);
        }
        printf("%d\n", ab - ba);
    }
    return 0;
}
size_t findab(const string &str, const int &startPos)
{
    int len = str.length();
    for (int i = startPos; i < len - 1; i++)
    {
        if (str[i] == 'a' && str[i + 1] == 'b')
        {
            return i;
        }
    }
    return string::npos;
}
size_t findba(const string &str, const int &startPos)
{
    int len = str.length();
    for (int i = startPos; i < len - 1; i++)
    {
        if (str[i] == 'b' && str[i + 1] == 'a')
        {
            return i;
        }
    }
    return string::npos;
}