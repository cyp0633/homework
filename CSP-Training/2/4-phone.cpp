//电话号码 CF898C
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
struct contact
{
    string name;
    string phonenum[30];
    int phoneCount = 0;
} c[20];
int checkSub(const string &a, const string &b); //返回1:a是b的后缀 -1:b是a的后缀
int compPhone(const string &a, const string &b);
int compName(const contact &a, const contact &b);
int main()
{
    int n, j, phoneN, t, peopleN = 0, i;
    string numTemp, nameTemp;
    scanf("%d", &n);
    for (int k = 0; k < n; k++)
    {
        cin >> nameTemp >> phoneN;
        for (i = 0; i < peopleN; i++)
        {
            if (c[i].name == nameTemp)
            {
                break;
            }
        }
        if (i == peopleN)
        {
            c[i].name = nameTemp;
            peopleN++;
        }
        for (int k = 0; k < phoneN; k++)
        {
            cin >> numTemp;
            for (j = 0; j < c[i].phoneCount; j++)
            {
                t = checkSub(numTemp, c[i].phonenum[j]);
                if (t == 1)
                {
                    break;
                }
                if (t == -1)
                {
                    c[i].phonenum[j] = numTemp;
                    break;
                }
            }
            if (j == c[i].phoneCount)
            {
                c[i].phonenum[c[i].phoneCount] = numTemp;
                c[i].phoneCount++;
            }
        }
    }
    printf("%d\n", peopleN);
    sort(c, c + peopleN, compName);
    for (int i = 0; i < peopleN; i++)
    {
        cout << c[i].name << ' ' << c[i].phoneCount << ' ';
        sort(c[i].phonenum, c[i].phonenum + c[i].phoneCount, compPhone);
        for (j = 0; j < c[i].phoneCount; j++)
        {
            cout << c[i].phonenum[j] << ' ';
        }
        putchar('\n');
    }
    return 0;
}
int checkSub(const string &a, const string &b)
{
    string subStr;
    if (a == b)
    {
        return 1;
    }
    int lenA = a.length(), lenB = b.length();
    if (lenA > lenB)
    {
        subStr = a.substr(lenA - lenB);
        if (subStr == b)
        {
            return -1;
        }
    }
    else if (lenA < lenB)
    {
        subStr = b.substr(lenB - lenA);
        if (subStr == a)
        {
            return 1;
        }
    }
    return 0;
}
int compPhone(const string &a, const string &b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}
int compName(const contact &a, const contact &b)
{
    return a.name < b.name;
}