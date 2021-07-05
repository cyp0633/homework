//n，还是n
#include <cstdio>
#include <iostream>
using namespace std;
bool check(const int &a, const int &b);
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        if (check(i, n))
        {
            printf("%d ", i);
        }
    }
    return 0;
}
bool check(const int &a, const int &b)
{
    if (a % b == 0)
    {
        return true;
    }
    if (to_string(a).find(to_string(b)) != string::npos)
    {
        return true;
    }
    return false;
}