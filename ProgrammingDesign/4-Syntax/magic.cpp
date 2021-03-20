//1 魔数
#include <cstdio>
#include <iostream>
using namespace std;
bool isMagic(int a);
int main()
{
    int n;
    scanf("%d", &n);
    if (isMagic(n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
bool isMagic(int a)
{
    int i, aNum[15] = {0};
    for (i = 9; i >= 0; i--)
    {
        aNum[i] = a % 10;
        a /= 10;
        if (a == 0)
        {
            break;
        }
    }
    for (; i <= 9; i++)
    {
        if (aNum[i] != 1)
        {
            return false;
        }
        else if (aNum[i + 1] == 4 && aNum[i + 2] == 4)
        {
            i += 2;
            continue;
        }
        else if (aNum[i + 1] == 4)
        {
            i++;
            continue;
        }
    }
    return true;
}