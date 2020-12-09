#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sHour, sMin, sSec, eHour, eMin, eSec;
    scanf("%d:%d:%d %d:%d:%d", &sHour, &sMin, &sSec, &eHour, &eMin, &eSec);
    int sTime = sHour * 3600 + sMin * 60 + sSec, eTime = eHour * 3600 + eMin * 60 + eSec, pTime = eTime - sTime;
    int pHour, pMin, pSec;
    pHour = pTime / 3600;
    pMin = (pTime % 3600) / 60;
    pSec = pTime % 60;
    cout << setfill('0');
    cout << pHour << ':' << setw(2) << pMin << ':' << setw(2) << pSec;
    //printf("%d:%2d:%2d", pHour, pMin, pSec);
    return 0;
}