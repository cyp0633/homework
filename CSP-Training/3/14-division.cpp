//A除以B
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string aStr;
    int a[1001], b, len;
    cin >> aStr >> b;
    len = aStr.length();            //a的长度
    if (len <= 1 && stoi(aStr) < b) //a<b的情况特判，一定是商为0余数为a
    {
        printf("0 %d", stoi(aStr));
        return 0;
    }
    for (int i = 0; i < len; i++) //将a从字符串中转移到int数组中存储，同时将ASCII码转化为数字
    {
        a[i] = aStr[i] - '0'; //'1'-'0'==1
    }
    for (int i = 0; i < len; i++)
    {
        a[i + 1] += a[i] % b * 10; //继承上一位的余数
        a[i] /= b;                 //进行这一位的除法运算
        if (i == 0 && a[i] == 0)   //得出的前导0不输出，i==0因为这个0只能存在于第一位
            continue;
        printf("%d", a[i]); //输出这一位的除法结果
    }
    printf(" %d", a[len] / 10); //输出最后的余数，就是个位除之后的余数
}