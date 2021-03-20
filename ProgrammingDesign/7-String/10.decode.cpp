//加密与解密
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
queue<int> getFactor(int n);
string reverse(string str, int len);
int main()
{
    string str;
    getline(cin, str);
    int f;
    queue<int> factor = getFactor(str.length());
    while (factor.size() > 0)
    {
        f = factor.front();
        factor.pop();
        str = reverse(str, f);
    }
    str = reverse(str, str.length());
    cout << str;
    return 0;
}
queue<int> getFactor(int n)
{
    queue<int> x;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            x.push(i);
        }
    }
    return x;
}
string reverse(string str, int len)
{
    string s = str;
    for (int i = 0; i < len; i++)
    {
        s[i] = str[len - i - 1];
    }
    return s;
}