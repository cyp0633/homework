//487-3279 UVa755
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void convCharToNum(char &c);
string standardify(const int &num);
int numify(const string &s);
int main()
{
    int n;
    int phonenum[100000];
    scanf("%d", &n);
    getchar();
    string numStr;
    memset(phonenum, 0x7f, sizeof(phonenum)); //初始化为很大的数
    for (int i = 0; i < n; i++)
    {
        getline(cin, numStr);
        for (string::iterator i = numStr.begin(); i != numStr.end(); i++)
        {
            convCharToNum(*i);
        }
        phonenum[i] = numify(numStr);
    }
    sort(phonenum, phonenum + n);
    int currentPhoneNum = -1, count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (phonenum[i] != currentPhoneNum)
        {
            if (count > 1)
            {
                cout << standardify(currentPhoneNum) << ' ' << count << '\n';
            }
            currentPhoneNum = phonenum[i];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return 0;
}
int numify(const string &s)
{
    int phonenum = 0;
    for (string::const_iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i >= '0' && *i <= '9')
        {
            phonenum = phonenum * 10 + *i-'0';
        }
    }
    return phonenum;
}
string standardify(const int &num)
{
    string numStr = to_string(num), standardStr;
    for (int i = 0; i < 3; i++)
    {
        standardStr.push_back(numStr[i]);
    }
    standardStr.push_back('-');
    for (int i = 3; i < 7; i++)
    {
        standardStr.push_back(numStr[i]);
    }
    return standardStr;
}
void convCharToNum(char &c)
{
    if (c == '-')
        return;
    if (c >= 'A' && c <= 'C')
    {
        c = '2';
        return;
    }
    if (c >= 'D' && c <= 'F')
    {
        c = '3';
        return;
    }
    if (c >= 'G' && c <= 'I')
    {
        c = '4';
        return;
    }
    if (c >= 'J' && c <= 'L')
    {
        c = '5';
        return;
    }
    if (c >= 'M' && c <= 'O')
    {
        c = '6';
        return;
    }
    if (c >= 'P' && c <= 'S')
    {
        c = '7';
        return;
    }
    if (c >= 'T' && c <= 'V')
    {
        c = '8';
        return;
    }
    if (c >= 'W' && c <= 'Y')
    {
        c = '9';
        return;
    }
}