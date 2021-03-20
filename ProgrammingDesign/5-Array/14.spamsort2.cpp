//垃圾分类 优化版
#include <cstdio>
#include <iostream>
using namespace std;
bool judge(int n);
void perform();
int main()
{
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        perform();
    }
}
bool judge(bool x, int n, bool w[], bool b[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (((x + 2) * (w[i] + 2) + b[i]) % 2 == 0)
        {
            x = 0;
        }
        else
        {
            x = 1;
        }
    }
    if (x) //x是奇数，是spam
    {
        return true;
    }
    else
    {
        return false;
    }
}
void perform()
{
    long long int countYes = 0, countNo = 0, minX, maxX;
    int n, i, j, w, b;
    bool wB[10000], bB[10000], ifOdd, ifEven;
    scanf("%d %lld %lld", &n, &minX, &maxX);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &w, &b);
        if (w % 2) //规定奇数为1，偶数为0
        {
            wB[i] = 1;
        }
        else
        {
            wB[i] = 0;
        }
        if (b % 2)
        {
            bB[i] = 1;
        }
        else
        {
            bB[i] = 0;
        }
    }
    ifOdd = judge(1, n, wB, bB); //奇数ID是不是spam，下同
    ifEven = judge(0, n, wB, bB);
    if (ifOdd && ifEven)
    {
        i = maxX - minX + 1;
        printf("0 %d\n", i);
        return;
    }
    else if ((!ifOdd) && (!ifEven))
    {
        i = maxX - minX + 1;
        printf("%d 0\n", i);
        return;
    }
    else
    {
        for (i = minX; i <= maxX; i++)
        {
            if (i % 2 == 0)
            {
                if (ifEven)
                {
                    countYes++;
                }
                else
                {

                    countNo++;
                }
            }
            else
            {
                if (ifOdd)
                {
                    countYes++;
                }
                else
                {
                    countNo++;
                }
            }
        }
    }
    printf("%d %d\n", countNo, countYes);
    return;
}