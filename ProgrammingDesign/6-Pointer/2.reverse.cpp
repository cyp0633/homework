//字符串反转
#include <iostream>
#include <cstring>
using namespace std;
void reverseStr(char *s);
int main()
{
    char str[201];
    gets(str);
    reverseStr(str);
    puts(str);

    return 0;
}

void reverseStr(char *s)
{
    char *p = s, *q = s;
    while (*q)
        q++;
    q--;
    while (p < q) /*  将指针p、q所指向位置的字符进行交换，之后指针p、q相向移动  */
    {

        char x = *q;
        *q = *p;
        *p = x;
        p++;
        q--;
    }
}