//带通配符的数
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int count;
void dfs(string w, string x);
int main()
{
    string w, x;
    while (cin >> w >> x)
    {
        count = 0;
        dfs(w, x);
        printf("%d\n", count);
    }
    return 0;
}
void dfs(string w, string x)
{
    unsigned int pos = w.find('?');
    if (pos == string::npos) //全部？替换完了
    {
        if (w > x)
        {
            count++;
        }
        return;
    }
    for (char i = '0'; i <= '9'; i++)
    {
        w[pos] = i;
        dfs(w, x);
    }
    return;
}