//IP地址
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
pair<string, string> splitStr(string &str, const char div);
int count(int num);
int main()
{
    string ip;
    int ip1, ip2, ip3, ip4, n, sum;
    scanf("%d", &n);
    pair<string, string> temp;
    for (; n > 0; n--)
    {
        cin >> ip;
        temp = splitStr(ip, '.');
        ip1 = stoi(temp.first);
        temp = splitStr(temp.second, '.');
        ip2 = stoi(temp.first);
        temp = splitStr(temp.second, '.');
        ip3 = stoi(temp.first);
        ip4 = stoi(temp.second);
        sum = count(ip1) + count(ip2) + count(ip3) + count(ip4);
        printf("%d\n", sum);
    }
    return 0;
}
pair<string, string> splitStr(string &str, const char div)
{
    string a, b;
    string::iterator i;
    for (i = str.begin(); i != str.end(); i++)
    {
        if (*i != div)
        {
            a.push_back(*i);
        }
        else
        {
            break;
        }
    }
    i++;
    for (; i != str.end(); i++)
    {
        b.push_back(*i);
    }
    return pair<string, string>(a, b);
}
int count(int num)
{
    int i, sum = 0;
    while (num != 0)
    {
        i = num % 2;
        if (i)
        {
            sum++;
        }
        num /= 2;
    }
    return sum;
}