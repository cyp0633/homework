//小数化分数
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int gcd(int a, int b);
void perform();
int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        perform();
    }
    return 0;
}
int gcd(int a, int b) //一定要a>=b
{
    return b == 0 ? a : gcd(b, a % b);
}
void perform()
{
    string num;
    getline(cin, num);
    int i, zs, xs, fm, loop, len, point, fz, g;
    len = num.length();
    bool ifLoop = false;
    for (i = 0; i < len; i++)
    {
        if (num[i] == '.')
        {
            point = i;
            zs = stoi(num.substr(0, i));
        }
        if (num[i] == '(')
        {
            ifLoop = true;
            if (num[i - 1]!='.')
            {
                xs = stoi(num.substr(point + 1, i - point));
            }
            else
            {
                xs = 0;
            }
            loop = stoi(num.substr(i + 1, len - i - 1));
            break;
        }
    }
    if (!ifLoop)
    {
        xs = stoi(num.substr(point + 1, len - point - 1));
        fz = zs * pow(10, len - point - 1) + xs;
        fm = pow(10, len - point - 1);
    }
    else
    {
        fm = pow(10, i - point - 1);
        fz = zs * fm + xs;
        fm *= pow(10, len - i - 2) - 1;
        fz = (pow(10, len - i - 2) - 1) * fz + loop;
    }
    g = gcd(fz, fm);
    fz /= g;
    fm /= g;
    printf("%d/%d\n", fz, fm);
    return;
}