//买房与选房
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
struct people
{
    char id[19];   /* 身份证号码 */
    int social;    /* 社保缴纳月数 */
    int area;      /* 现有住房面积 */
    char date[11]; /* 申报日期 */
};
bool compPrior(const pair<long long int, people> a, const pair<long long int, people> b);
people *getMess(int &n);
long long int getPriority(people &a);
int getDay(char date[]);
pair<long long int, people> p[100000];
int firstForSamePriority[100000], lastForSamePriority[100000];
int main()
{
    people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */
    int n;          /* n为报名人数，通过调用函数getMess获取 */
    person = getMess(n);
    // ...
    for (int i = 0; i < n; i++)
    {
        p[i].second = person[i];
        p[i].first = getPriority(person[i]);
    }
    delete[] person;
    stable_sort(p, p + n, compPrior);
    firstForSamePriority[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].first == p[i - 1].first)
        {
            firstForSamePriority[i] = firstForSamePriority[i - 1];
        }
        else
        {
            firstForSamePriority[i] = i;
        }
    }
    lastForSamePriority[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (p[i].first == p[i + 1].first)
        {
            lastForSamePriority[i] = lastForSamePriority[i + 1];
        }
        else
        {
            lastForSamePriority[i] = i;
        }
    }
    int m, t, j;
    char id[19];
    cin >> m >> t;
    getchar(); //吸收行尾的回车
    for (int i = 0; i < t; i++)
    {
        gets(id);
        for (j = 0; j < n; j++)
        {
            if (equal(p[j].second.id, p[j].second.id + 18, id))
            {
                break;
            }
        }
        if (p[j].first == -1000000000000) //没资格
        {
            printf("Sorry\n");
            continue;
        }
        if (firstForSamePriority[j] >= m) //套数不够了
        {
            printf("Sorry");
            continue;
        }
        if (lastForSamePriority[j] < m)
        {
            if (firstForSamePriority[j] == lastForSamePriority[j]) //第2种情况
            {
                printf("%d\n", j + 1);
            }
            else
            {
                printf("%d %d\n", firstForSamePriority[j] + 1, lastForSamePriority[j] + 1);
            }
            continue;
        }
        printf("%d/%d\n", m - firstForSamePriority[j], lastForSamePriority[j] - firstForSamePriority[j] + 1);
    }
    return 0;
}
people *getMess(int &n) /* 将文件数据读入内存 */

{
    FILE *fp;
    // fp = fopen("C:/Users/cyp0633/OneDrive/Code/homework/CSP-Training/1/house.bin", "rb"); //debug
    fp = fopen("house.bin", "rb"); //release
    fseek(fp, -1 * (long)sizeof(int), 2);
    fread(&n, sizeof(int), 1, fp);
    rewind(fp);
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);
    fclose(fp);
    return tmp;
}
long long int getPriority(people &a)
{
    int time = getDay(a.date);
    if (a.area == 0 && a.social > 24) //刚性需求
    {
        return a.social * 10000000000 - time;
    }
    else if (a.area > 0) //改善性需求
    {
        return -100000000 * a.area - time;
    }
    else //没有购房资格
    {
        return -1000000000000;
    }
}
int getDay(char date[]) //这是一个不准确的计算天数算法，但精度应该够用
{
    for (int i = 0; i < 10; i++)
    {
        date[i] -= '0';
    }
    int year = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];
    int mon = date[3] * 10 + date[4];
    int day = date[0] * 100 + date[1] * 10 + date[2];
    return year * 365 + mon * 30 + day;
}
bool compPrior(const pair<long long int, people> a, const pair<long long int, people> b)
{
    return a.first > b.first;
}