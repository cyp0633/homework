//最大报销额 HDU 1864
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
double value[30], maxv;
double getValue(const int &n, const string &str);
double splitValue(const string &str);
void dfs(int n, double value, const int &num, const double &valueMax); //现在要找第几个物品，当前价值多少，总共几个物品，最大价值多少
int main()
{
    double valueMax;
    int n, article;
    string strTemp;
    while (cin >> valueMax >> n)
    {
        if (n == 0)
        {
            break;
        }
        memset(value, 0, sizeof(value));
        maxv = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> article;
            getline(cin, strTemp);
            value[i] = getValue(article, strTemp);
        }
        dfs(0, 0, n, valueMax);
        printf("%.2lf\n", maxv);
    }
    return 0;
}
double getValue(const int &n, const string &str)
{
    double value = 0.0;
    string temp;
    stringstream ss;
    ss << str;
    while (ss >> temp)
    {
        if (temp[0] < 'A' || temp[0] > 'C') //种类不对报不了
        {
            return 0.0;
        }
        value += splitValue(temp);
        if (value > 1000.0)
        {
            return 0.0;
        }
    }
    return value;
}
double splitValue(const string &str) //单件物品的价值获取
{
    double value = stod(str.substr(str.find(':') + 1));
    if (value > 600.0)
    {
        return 0.0;
    }
    return value;
}
void dfs(int n, double currentVal, const int &num, const double &valueMax)
{
    if (currentVal > valueMax)
    {
        return;
    }
    if (n == num)
    {
        if (currentVal > maxv)
        {
            maxv = currentVal;
        }
        return;
    }
    dfs(n + 1, currentVal + value[n], num, valueMax); //放
    dfs(n + 1, currentVal, num, valueMax);
    return;
}