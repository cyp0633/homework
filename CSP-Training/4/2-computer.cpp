//最简单的计算机
#include <cstdio>
#include <iostream>
using namespace std;
int m1, m2, r1, r2, r3;
int main()
{
    string temp;
    while (cin >> m1 >> m2)
    {
        cin >> temp;
        for (string::iterator i = temp.begin(); i != temp.end(); i++)
        {
            switch (*i)
            {
            case 'A':
                r1 = m1;
                break;
            case 'B':
                r2 = m2;
                break;
            case 'C':
                m1 = r3;
                break;
            case 'D':
                m2 = r3;
                break;
            case 'E':
                r3 = r1 + r2;
                break;
            case 'F':
                r3 = r1 - r2;
                break;
            }
        }
        printf("%d,%d\n", m1, m2);
    }
    return 0;
}