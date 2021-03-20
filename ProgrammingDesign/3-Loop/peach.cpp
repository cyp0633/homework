//17 桃子问题
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);
    long long int peach = 1;
    for (i = 1; i < n; i++)
    {
        peach = (peach + 1) * 2;
    }
    printf("%lld", peach);
    return 0;
}