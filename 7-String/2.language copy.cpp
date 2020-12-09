//古老的语言
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
bool yy(char s);
int main()
{
    int len, i, j;
    string word;
    bool y[1000] = {0};
    getline(cin, word);
    len = word.length();
    for (i = 0; i < len; i++)
    {
        y[i] = yy(word[i]);
    }
    y[len] = false;
    for (i = 0; i < len; i++)
    {
        if (yy(word[i])==false)
        {
            if (word[i] != 'n' && (yy(word[i + 1])==false||i==len-1))
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
bool yy(char s)
{
    if (s == 'a' || s == 'o' || s == 'u' || s == 'i' || s == 'e')
    {
        return true;
    }
    else
    {
        return false;
    }
}