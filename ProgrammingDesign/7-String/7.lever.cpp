//杠杆
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
void perform();
int main()
{
    int t, i;
    scanf("%d\n", &t);
    for (i = 0; i < t; i++)
    {
        perform();
    }
    return 0;
}
void perform()
{
    string lever;
    getline(cin, lever);
    int i, len, pivot = 0, leftWeight = 0, rightWeight = 0;
    len = lever.length();
    while (lever[pivot] != '^') //确定支点的位置
    {
        pivot++;
    }
    for (i = 0; i < pivot; i++)
    {
        if (lever[i] != '=')
        {
            leftWeight += (pivot - i) * (lever[i] - '0');
        }
    }
    for (i = pivot + 1; i < len; i++)
    {
        if (lever[i] != '=')
        {
            rightWeight += (i - pivot) * (lever[i] - '0');
        }
    }
    if (rightWeight > leftWeight)
    {
        printf("right\n");
        return;
    }
    if (leftWeight > rightWeight)
    {
        printf("left\n");
        return;
    }
    printf("balance\n");
    return;
}