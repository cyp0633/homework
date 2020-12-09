//这是一个几位数
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char num[100];
    cin >> num;
    bool if0 = true;
    int len = strlen(num);
    printf("%d ", len);
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] != '0')
            if0 = false;
        if (!if0)
            printf("%c", num[i]);
    }
    if (if0)
        printf("0"); //第三个点特判
    return 0;
}