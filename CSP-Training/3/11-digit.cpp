//数码管
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
bool isTransferrable[10][10] = {{1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
                                {1, 1, 0, 1, 1, 0, 0, 1, 1, 1},
                                {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                                {0, 1, 0, 1, 0, 0, 0, 1, 1, 1},
                                {0, 1, 0, 0, 1, 0, 0, 0, 1, 1},
                                {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                                {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                                {1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {0, 1, 0, 1, 1, 1, 0, 1, 1, 1}};
main()
{
    int temp, lastNum;
    string tempStr;
    while (getline(cin, tempStr))
    {
        if (tempStr == "-1")
        {
            break;
        }
        stringstream ss;
        ss << tempStr;
        ss >> lastNum;
        while (ss >> temp)
        {
            if (!isTransferrable[lastNum][temp])
            {
                printf("NO\n");
                break;
            }
            lastNum = temp;
        }
        if (ss.eof())
        {
            printf("YES\n");
        }
    }
    return 0;
}