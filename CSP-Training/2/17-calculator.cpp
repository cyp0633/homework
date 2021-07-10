//小A的计算器
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getNum(const string &s);
int charToNum(const char &c);
char numToChar(const int &n);
string getStr(const vector<int> &n);
int main()
{
    int n, jw[11];
    string aStr, bStr;
    vector<int> aNum, bNum;
    scanf("%d", &n);
    while (n--)
    {
        memset(jw, 0, sizeof(jw));
        cin >> aStr >> bStr;
        aNum = getNum(aStr);
        bNum = getNum(bStr);
        while (aNum.size() < bNum.size()) //补0，否则怕Segmentation Fault
        {
            aNum.push_back(0);
        }
        while (bNum.size() < aNum.size())
        {
            bNum.push_back(0);
        }
        for (int i = 0; i < aNum.size(); i++)
        {
            aNum[i] = aNum[i] + bNum[i] + jw[i];
            jw[i + 1] = aNum[i] / 26;
            aNum[i] %= 26;
        }
        aNum.push_back(jw[aNum.size()]);
        cout << getStr(aNum) << '\n';
    }
}
vector<int> getNum(const string &s)
{
    vector<int> n;
    for (string::const_reverse_iterator i = s.rbegin(); i != s.rend(); i++)
    {
        n.push_back(charToNum(*i));
    }
    return n;
}
int charToNum(const char &c)
{
    return c - 'a';
}
char numToChar(const int &n)
{
    return n + 'a';
}
string getStr(const vector<int> &n)
{
    string str;
    for (vector<int>::const_reverse_iterator i = n.rbegin() + 1; i != n.rend(); i++)
    {
        str.push_back(numToChar(*i));
    }
    return str;
}
