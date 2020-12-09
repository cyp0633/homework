//18 完美数
#include <cstdio>
#include <iostream>
using namespace std;
int ysh(int x);
int main()
{
    int n;
    scanf("%d", &n);
    if (ysh(n) == n)
        printf("true");
    else
        printf("false");
    return 0;
}
int ysh(int x)
{
    int sum = 0;
    for (int m = 1; m < x; m++)
    {
        if (x % m == 0)
        {
            sum += m;
        }
    }
    return sum;
}