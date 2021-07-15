//数字统计
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int count[10] = {0};
    string num;
    cin >> num;
    for (string::iterator i = num.begin(); i != num.end(); i++)
    {
        count[*i - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (count[i] != 0)
        {
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}