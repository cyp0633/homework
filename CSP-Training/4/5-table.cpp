//小希的数表
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
inline bool solve(const int &ab, const int &ac, const int &bc, int a[]);
int main()
{
    int s[4950], a[100], n, numCount, i, j, k;
    bool isProperSolution;
    multiset<int>::iterator sumPos;
    while (cin >> n)
    {
        memset(s, 0, sizeof(s));
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < (n - 1) * n / 2; i++)
        {
            scanf("%d", &s[i]);
        }
        for (i = 2; i < (n - 1) * n / 2; i++) //枚举a2+a3
        {
            memset(a, 0, sizeof(a));
            if (!solve(s[0], s[1], s[i], a)) //不是整数
            {
                continue;
            }
            if (a[0] <= 0 || a[1] <= 0 || a[2] <= 0) //不符合正整数的条件
            {
                continue;
            }
            isProperSolution = true; //假设这个解是合适的
            multiset<int> sum{s[i]}; //a_2+a_3的和先存在set中
            numCount = 3;
            for (j = 2; j < (n - 1) * n / 2; j++)
            {
                sumPos = sum.find(s[j]);
                if (numCount == n) //假定所有数都找出来之后，这些和应该都记录在set里了
                {
                    if (sumPos == sum.end())
                    {
                        isProperSolution = false;
                        break;
                    }
                }
                if (sumPos != sum.end()) //s[j]在set中存在
                // if (sum.contains(s[j]))      //C++20的方法
                {
                    sum.erase(sumPos);
                    continue;
                }
                a[numCount] = s[j] - a[0];
                if (a[numCount] <= 0) //不是正整数
                {
                    break;
                }
                for (k = 1; k < numCount; k++)
                {
                    sum.insert(a[numCount] + a[k]); //将该数和前面所有数的和加入set
                }
                numCount++;
            }
            if (numCount == n && isProperSolution) //找到解了
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
    return 0;
}
inline bool solve(const int &ab, const int &ac, const int &bc, int a[])
{
    int sum = (ab + ac + bc);
    if (sum % 2 != 0)
    {
        return false;
    }
    sum /= 2;
    a[2] = sum - ab;
    a[1] = sum - ac;
    a[0] = sum - bc;
    return true;
}