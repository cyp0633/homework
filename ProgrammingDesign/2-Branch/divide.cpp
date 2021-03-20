#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    bool d3 = !(n % 3), d5 = !(n % 5), d7 = !(n % 7);
    if (d3 && d5 && d7)
        printf("It\'s divisible by 3,5,7");
    else if (!d3 && d5 && d7)
        printf("It\'s divisible by 5,7");
    else if (d3 && !d5 && d7)
        printf("It\'s divisible by 3,7");
    else if (d3 && d5 && !d7)
        printf("It\'s divisible by 3,5");
    else if (!d3 && !d5 && d7)
        printf("It\'s divisible by 7");
    else if (!d3 && d5 && !d7)
        printf("It\'s divisible by 5");
    else if (d3 && !d5 && !d7)
        printf("It\'s divisible by 3");
    else if (!d3 && !d5 && !d7)
        printf("null");
    return 0;
}