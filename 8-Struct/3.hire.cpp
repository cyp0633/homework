//招聘
#include <cstdio>
#include <iostream>
using namespace std;
struct employee
{
    int skill;        //k
    int intelligence; //i
    int loyalty;      //e
    bool knockout;
} e[500000];
int main()
{
    int n, i, j, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e[i].skill);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e[i].intelligence);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e[i].loyalty);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (e[j].knockout || i == j)
            {
                continue;
            }
            if (e[i].skill > e[j].skill && e[i].intelligence > e[j].intelligence && e[i].loyalty > e[j].loyalty)
            {
                e[j].knockout = true;
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}