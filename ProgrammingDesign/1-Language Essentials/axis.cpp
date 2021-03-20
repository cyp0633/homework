#include <cstdio>
#include <iostream>
using namespace std;
struct axis
{
    int x, y;
} a[3];
int main()
{
    scanf("(%d,%d),(%d,%d),(%d,%d)", &a[0].x, &a[0].y, &a[1].x, &a[1].y, &a[2].x, &a[2].y);
    //cin>>'('>>a[0].x>>','>>a[0].y>>"),(">>a[1].x>>','>>a[1].y>>"),(">>a[2].x>>','>>a[2].y>>')';
    for (int i = 0; i < 3; i++)
    {
        printf("[%d,%d]\n", a[i].x, a[i].y);
    }
    return 0;
}
