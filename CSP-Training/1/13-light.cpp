//开关与灯
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n, m; //n个开关m个灯
    string matrix;
    bool opened[2000], hasUnlitLight;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        hasUnlitLight = false;
        cin >> matrix;
        for (int j = 0; j < m; j++)
        {
            if (!opened[j] && matrix[j] == '1')
            {
                hasUnlitLight = true;
                opened[j] = true;
            }
        }
        if (!hasUnlitLight)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}