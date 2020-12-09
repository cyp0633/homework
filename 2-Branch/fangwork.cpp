#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int salary, dist;
    char vacation;
    scanf("%d %c %d", &salary, &vacation, &dist);
    if ((salary >= 5000) + (vacation == 'y') + (dist <= 2000) >= 2)
        printf("Accept");
    else
        printf("Refuse");
    return 0;
}