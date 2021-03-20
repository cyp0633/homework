//2 小熊买糖果
#include <cstdio>
#include <iostream>
using namespace std;
int getCandy(int, int);
int main()
{
    int k, r;
    scanf("%d %d", &k, &r);
    int result = getCandy(k, r);
    printf("%d", result);
    return 0;
}
int getCandy(int k, int r)
{
    int n;
    for (n = 1; true; n++)
    {
        if ((n * k) % 10 == r || (n * k) % 10 == 0)
        {
            return n;
        }
    }
}