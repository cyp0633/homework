//飞机起飞时间安排
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n, s, h, m, aTime[100] = {0}, eTime, eHour, eMin;
    scanf("%d %d", &n, &s);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &h, &m);
        aTime[i] = 60 * h + m;
        if(i==0&&(aTime[0]>=s+1))
        {
            printf("0 0");
            return 0;
        }
        /*if ((aTime[i] - aTime[i - 1] - 2 >= 2 * s) && i != 0)
        {
            eTime = aTime[i - 1] + s + 1;
            eHour = eTime / 60;
            eMin = eTime % 60;
            printf("%d %d",eHour,eMin);
            return 0;
        }*/
    }
    if((aTime[0]-aTime[n-1]+1440-2>=2*s)&&(aTime[n-1]-1439+s>0))
    {
        eTime=aTime[n-1]+s+1-1440;
        eHour=eTime/60;
        eMin=eTime%60;
        printf("%d %d",eHour,eMin);
        return 0;
    }
    for(i=1;i<n;i++)
    {
        eTime = aTime[i - 1] + s + 1;
        eHour = eTime / 60;
        eMin = eTime % 60;
        printf("%d %d",eHour,eMin);
        return 0;
    }
    eTime=aTime[n-1]+s+1;
    eHour=eTime/60;
    eMin=eTime%60;
    printf("%d %d",eHour,eMin);
    return 0;
}