//循环数
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string multiply(string a, int b);
bool checkLoop(string a, string b);
int main()
{
    string num, s;
    int len;
    getline(cin, num);
    len = num.length();
    for (int i = 0; i < len; i++)
    {
        num[i] -= '0';
    }
    for (int i = 2; i < len; i++)
    {
        s = multiply(num, i);
        if (s == "-1") //进位的情况，那肯定不能是循环数了啊
        {
            printf("No");
            return 0;
        }
        if (!checkLoop(num, s))
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
string multiply(string a, int b)
{
    int len = a.length();
    int add[60] = {0};
    for (int i = len - 1; i > 0; i--)
    {
        a[i] = a[i] * b + add[i];
        add[i - 1] = a[i] / 10;
        a[i] %= 10;
    }
    a[0] = a[0] * b + add[0];
    if (a[0] > 9)
    {
        return "-1";
    }
    else
        return a;
}
bool checkLoop(string a, string b)
{
    int len = a.length();
    string lTemp, rTemp;
    if (a == b)
    {
        return true;
    }
    for (int i = 1; i < len; i++) //i是分割下来前一个子串的最后一位
    {
        lTemp = b.substr(0, i);
        if (a.find(lTemp) == string::npos)
        {
            continue;
        }
        rTemp = b.substr(i, len - i);
        if (a.find(rTemp) != string::npos)
        {
            return true;
        }
    }
    return false;
}