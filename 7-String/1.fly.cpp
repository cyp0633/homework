//飞来飞去
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
void perform();
int main()
{
    int a, t;
    scanf("%d\n", &t);
    for (a = 0; a < t; a++)
    {
        perform();
    }
    return 0;
}
void perform()
{
    int i, n, s2t = 0, t2s = 0;
    string s;
    cin >> n >> s;
    for (i = 1; i < n; i++)
    {
        if (s[i] == 'S' && s[i - 1] == 'T')
        {
            t2s++;
        }
        if (s[i - 1] == 'S' && s[i] == 'T')
        {
            s2t++;
        }
    }
    if (s2t > t2s)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return;
}