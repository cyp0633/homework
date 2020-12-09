//排队喝水
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
void perform();
struct student
{
    int arrTime;
    int ddlTime;
};
int main()
{
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        perform();
    }
}
void perform()
{
    queue<student> q;
    int n, l, r, i, j, t = 0;
    student a;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a.arrTime, &a.ddlTime);
        q.push(a);
    }
    for (t = 1; !q.empty(); t++)
    {
        if (q.front().arrTime > t)
        {
            continue;
        }
        while (q.front().ddlTime < t)
        {
            printf("0 ");
            q.pop();
            if (q.empty()) //就怕它瞎jb pop给整RE了
            {
                break;
            }
        }
        if (q.empty())
        {
            break;
        }
        printf("%d ", t);
        q.pop();
    }
    printf("\n");
    return;
}