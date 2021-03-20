//阿迪看医生
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n, s[1000], d[1000], time = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &s[i], &d[i]);
        for (j = s[i]; true; j += d[i])
        {
            if (j > time)
            {
                time = j;
                break;
            }
        }
    }
    printf("%d", time);
}