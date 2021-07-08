//拼写检查 POJ 1035
#include <cstdio>
#include <iostream>
using namespace std;
bool checkReplace(const string &a, const string &b);
bool checkDelete(const string &a, const string &b);
int main()
{
    string dict[10000], temp;
    int dictCount = 0, i;
    while (getline(cin, temp))
    {
        if (temp == "#")
        {
            break;
        }
        dict[dictCount] = temp;
        dictCount++;
    }
    while (getline(cin, temp))
    {
        if (temp == "#")
        {
            break;
        }
        for (i = 0; i < dictCount; i++)
        {
            if (temp == dict[i])
            {
                cout << temp << " is correct\n";
                break;
            }
        }
        if (i != dictCount)
        {
            continue;
        }
        cout << temp << ':';
        for (int i = 0; i < dictCount; i++)
        {
            if (checkReplace(temp, dict[i]) || checkDelete(temp, dict[i]) || checkDelete(dict[i], temp)) //删除倒过来不就是添加了嘛
            {
                cout << ' ' << dict[i];
            }
        }
        putchar('\n');
    }
}
bool checkReplace(const string &a, const string &b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    int diff = 0;
    for (int i = 0; i < a.length(); i++)
    {
        diff += (a[i] != b[i]);
        if (diff > 1)
        {
            return false;
        }
    }
    return true;
}
bool checkDelete(const string &a, const string &b)
{
    if (b.length() - a.length() != 1)
    {
        return false;
    }
    bool deleted = false;
    string::const_iterator i = a.begin(), j = b.begin();
    for (int t = 0; t < a.length(); t++)
    {
        if (*i != *j)
        {
            if (deleted)
            {
                return false;
            }
            j++;
            deleted = true;
            ;
            if (*i != *j)
            {
                return false;
            }
        }
        i++;
        j++;
    }
    return true;
}