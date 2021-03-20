#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 60)
        printf("E");
    else if (n < 70)
        printf("D");
    else if (n < 80)
        printf("C");
    else if (n < 90)
        printf("B");
    else
        printf("A");
    return 0;
    return 0;
}