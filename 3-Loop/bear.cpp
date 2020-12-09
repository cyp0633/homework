//21 小熊与糖果
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, a, b, i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d%d", &a, &b);
        for (j = 1; true; j++)
        {
            if (j % 2 == 1)
            {
                a -= j;
                if (a < 0)
                {
                    printf("Bob\n");
                    break;
                }
            }
            else
            {
                b -= j;
                if (b < 0)
                {
                    printf("Limak\n");
                    break;
                }
            }
        }
    }
    return 0;
}