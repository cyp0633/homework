//10 松雅喜欢玩纸牌
#include <cstdio>
#include <iostream>
using namespace std;
struct card
{
    char color, point;
} pCard[5], hCard;
int main()
{
    scanf("%c%c\n", &hCard.point, &hCard.color);
    int i;
    for (i = 0; i < 4; i++)
    {
        scanf("%c%c\n", &pCard[i].point, &pCard[i].color);
        if (pCard[i].point == hCard.point || pCard[i].color == hCard.color)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}