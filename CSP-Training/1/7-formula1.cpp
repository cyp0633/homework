//F1方程式冠军
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int rankScore[100] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
struct racer
{
    string name;
    int point = 0;
    int champion = 0;
    int pos[100] = {0};
};
bool originalComp(const racer &a, const racer &b);
bool altComp(const racer &a, const racer &b);
int main()
{
    racer r[100];
    int t, n, rCount = 0, rNum;
    string rName;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            cin >> rName;
            rNum = -1;
            for (int k = 0; k < rCount; k++)
            {
                if (r[k].name == rName)
                {
                    rNum = k;
                    break;
                }
            }
            if (rNum == -1)
            {
                rNum = rCount;
                r[rNum].name = rName;
                rCount++;
            }
            if(j<10)r[rNum].pos[j]++;
            r[rNum].point+=rankScore[j];
        }
    }
    sort(r,r+rCount,originalComp);
    cout<<r[0].name<<endl;
    sort(r,r+rCount,altComp);
    cout<<r[0].name<<endl;
    return 0;
}
bool originalComp(const racer &a, const racer &b)
{
    if(a.point!=b.point)
    {
        return a.point>b.point;
    }
    for(int i=0;i<10;i++)
    {
        if(a.pos[i]!=b.pos[i])
        {
            return a.pos[i]>b.pos[i];
        }
    }
    return true;
}
bool altComp(const racer &a, const racer &b)
{
    if(a.pos[0]!=b.pos[0])
    {
        return a.pos[0]>b.pos[0];
    }
    if(a.point!=b.point)
    {
        return a.point>b.point;
    }
    for(int i=1;i<10;i++)
    {
        if(a.pos[i]!=b.pos[i])
        {
            return a.pos[i]>b.pos[i];
        }
    }
    return true;
}