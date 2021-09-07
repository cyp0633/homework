//7，还是7
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temp;
    int count = 0, num[30000];
    for (int i = 7; i < 30000; i++)
    {
        if (i % 7 == 0)
        {
            num[count] = i;
            count++;
            continue;
        }
        if (to_string(i).find('7') != string::npos)
        {
            num[count] = i;
            count++;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < count; i++)
    {
        if (num[i] > n)
        {
            break;
        }
        printf("%d\n", num[i]);
    }
    return 0;
}