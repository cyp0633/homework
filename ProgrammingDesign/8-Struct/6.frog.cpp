#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Frog
{
public:
    Frog()
    {
        pos = 0;
        len = 0;
        flyCount = 0;
        num = 0;
    }
    int pos, len, num, flyCount;
};
bool comp1(Frog a, Frog b);
bool comp2(Frog a,Frog b);
int main()
{
    int m, n, i, j, weight, pos; //m是蚊子，n是青蛙
    cin >> n >> m;
    // Frog *frog = new Frog[200000];
    Frog frog[n];
    for (i = 0; i < n; i++)
    {
        frog[i].num = i + 1;
        cin >> frog[i].pos >> frog[i].len;
    }
    sort(frog, frog + n, comp1);
    for (i = 0; i < m; i++)
    {
        cin >> pos >> weight;
        if (frog[0].pos > pos)
        {
            continue;
        }
        for (j = 0; j < n; j++)
        {

            if (frog[j].pos + frog[j].len >= pos&&frog[j].pos<=pos)
            {
                frog[j].len += weight;
                frog[j].flyCount++;
                break;
            }
        }
    }
    sort(frog,frog+n,comp2);
    for (i = 0; i < n; i++)
    {
        cout << frog[i].flyCount << ' ' << frog[i].len << '\n';
    }
    return 0;
}
bool comp1(Frog a, Frog b)
{
    return a.pos < b.pos;
}
bool comp2(Frog a,Frog b)
{
    return a.num<b.num;
}