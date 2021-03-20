#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, rn, score = 0;
    char type;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c\n", &type);
        if (type == 'r')
        {
            scanf("%d\n", &rn);
            score += rn;
        }
        if (type == 'y')
            score += 2;
        if (type == 'g')
            score += 3;
        if (type == 'c')
            score += 4;
        if (type == 'b')
            score += 5;
        if (type == 'p')
            score += 6;
        if (type == 'B')
            score += 7;
    }
    printf("%d", score);
    return 0;
}