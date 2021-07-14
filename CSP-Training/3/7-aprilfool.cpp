//愚人节的礼物
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string str;
    int length;
    while (cin >> str)
    {
        length = 0;
        for (string::iterator i = str.begin(); i != str.end(); i++)
        {
            if (*i == 'B')
            {
                printf("%d\n", length);
                break;
            }
            switch (*i)
            {
            case '(':
            {
                length++;
                break;
            }
            case ')':
            {
                length--;
                break;
            }
            }
        }
    }
    return 0;
}