//Caesar密码
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string temp;
    while (1) //START
    {
        getline(cin, temp);
        if (temp == "ENDOFINPUT")
        {
            return 0;
        }
        getline(cin, temp); //原文
        for (string::iterator i = temp.begin(); i != temp.end(); i++)
        {
            if (*i >= 'A' && *i <= 'Z')
            {
                *i -= 5;
                if (*i < 'A')
                {
                    *i += 26;
                }
            }
            putchar(*i);
        }
        putchar('\n');
        getline(cin, temp); //END
    }
    return 0;
}