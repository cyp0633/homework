//飞行棋 HDU 2240
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int a, b, c;
    int n, lPos, yPos;
    string type;
    pair<int, bool> array[200]; //好像这个second没用了?
    while (cin>>n>>a>>b>>c)
    {
        lPos = yPos = 0;
        for (int i = 0; i < n; i++)
        {
            if(cin.peek()==EOF)
            {
                return 0;
            }
            cin >> type;
            if (type == "N")
            {
                array[i].first = -1;
            }
            else
            {
                array[i].first = stoi(type.substr(1)); //把G截掉
            }
            array[i].second = false; //强迫症而已
        }
        for (int i = 0;; i++)
        {
            //Lele
            c = (a * c + b) % 6 + 1;
            lPos += c;
            if (lPos > n - 1)
            {
                lPos = 2 * n - lPos - 2; //会不会走到0之前啊？并不会，Gx<N
            }
            if (lPos == yPos)
            {
                lPos = 0;
            }
            while (array[lPos].first != -1)
            {
                lPos = array[lPos].first;
                if (lPos == n - 1)
                {
                    break;
                }
                if (lPos == yPos)
                {
                    lPos = 0;
                }
            }
            if (lPos == n - 1)
            {
                printf("Lele\n");
                break;
            }
            //Yueyue
            c = (a * c + b) % 6 + 1;
            yPos += c;
            if (yPos > n - 1)
            {
                yPos = 2 * n - yPos - 2;
            }
            if (yPos == lPos)
            {
                yPos = 0;
            }
            while (array[yPos].first != -1)
            {
                yPos = array[yPos].first;
                if (yPos == lPos)
                {
                    yPos = 0;
                }
                if (yPos == n - 1)
                {
                    break;
                }
            }
            if (yPos == n - 1)
            {
                printf("Yueyue\n");
                break;
            }
        }
        if(cin.peek()==EOF)
        {
            return 0;
        }
    }
    return 0;
}