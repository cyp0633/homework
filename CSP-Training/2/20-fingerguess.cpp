//锤子剪刀布
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, jcCount = 0, jjCount = 0, jbCount = 0, ycCount = 0, yjCount = 0, ybCount = 0, win = 0, lose = 0, avg = 0;
    char j, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> j >> y;
        if (j == 'C' && y == 'J')
        {
            win++;
            jcCount++;
        }
        else if (j == 'C' && y == 'C')
        {
            avg++;
        }
        else if (j == 'C' && y == 'B')
        {
            lose++;
            ybCount++;
        }
        else if (j == 'J' && y == 'C')
        {
            lose++;
            ycCount++;
        }
        else if (j == 'J' && y == 'J')
        {
            avg++;
        }
        else if (j == 'J' && y == 'B')
        {
            jjCount++;
            win++;
        }
        else if (j == 'B' && y == 'C')
        {
            jbCount++;
            win++;
        }
        else if (j == 'B' && y == 'J')
        {
            yjCount++;
            lose++;
        }
        else if (j == 'B' && y == 'B')
        {
            avg++;
        }
    }
    printf("%d %d %d\n%d %d %d\n", win, avg, lose, lose, avg, win);
    if (jbCount >= jjCount && jbCount >= jcCount)
    {
        putchar('B');
    }
    else if (jcCount >= jbCount && jcCount >= jjCount)
    {
        putchar('C');
    }
    else
    {
        putchar('J');
    }
    putchar(' ');
    if (ybCount >= ycCount && ybCount >= yjCount)
    {
        putchar('B');
    }
    else if (ycCount >= ybCount && ycCount >= yjCount)
    {
        putchar('C');
    }
    else
    {
        putchar('J');
    }
    return 0;
}