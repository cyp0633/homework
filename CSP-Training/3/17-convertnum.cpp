//字符串数字置换
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int count[10] = {0};
    string str, conversion[10] = {"(Zero)", "(One)", "(Two)", "(Three)", "(Four)", "(Five)", "(Six)", "(Seven)", "(Eight)", "(Nine)"};
    getline(cin, str);
    for (string::iterator i = str.begin(); i != str.end(); i++)
    {
        if (*i >= '0' && *i <= '9')
        {
            cout << conversion[*i - '0'];
            count[*i - '0']++;
        }
        else
        {
            cout << *i;
        }
    }
    putchar('\n');
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", count[i]);
    }
    return 0;
}