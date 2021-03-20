//音乐DJ与回响Bass
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    bool x = false;
    getline(cin, word);
    int i = 0, len;
    len = word.length();
    while (word.substr(i, 3) == "WUB")
    {
        i += 3;
    }
    for (; i < len; i++)
    {
        if (word.substr(i, 3) == "WUB")
        {
            if (!x)
            {
                putchar(' ');
                x = true;
            }
            i += 2;
            continue;
        }
        x = false;
        cout << word[i];
    }
    return 0;
}