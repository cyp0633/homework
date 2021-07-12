//缺席考试的是谁
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    pair<string, int> student[10000];
    int n, nameNum, j;
    string tempName;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        getchar();
        nameNum = 0;
        for (int i = 0; i < n * 2 - 1; i++)
        {
            getline(cin, tempName);
            for (j = 0; j < nameNum; j++)
            {
                if (student[j].first == tempName)
                {
                    student[j].second++;
                    break;
                }
            }
            if (j == nameNum) //没找到
            {
                student[j].first = tempName;
                student[j].second = 1;
                nameNum++;
            }
        }
        for (int i = 0; i < nameNum; i++)
        {
            if (student[i].second % 2 == 1)
            {
                cout << student[i].first << endl;
                break;
            }
        }
    }
    return 0;
}