//岁月留痕
#include <cstdio>
#include <iostream>
using namespace std;
const int monstr[36] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int i, j, n, cmpstr[36], count29 = 0;
    ;
    bool find = false;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &cmpstr[i]);
    }
    for (i = 0; i < 12; i++)
    {
        find = true;
        for (j = 0; j < n; j++)
        {
            if (cmpstr[j] == monstr[i + j] || (cmpstr[j] == 29 && monstr[i + j] == 28))
            {
                if (cmpstr[j] == 29)
                {
                    count29++;
                    if (count29 == 2)
                    {
                        printf("No");
                        return 0;
                    }
                }
                continue;
            }
            else
            {
                find = false;
                break;
            }
        }
        if (find == true)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}