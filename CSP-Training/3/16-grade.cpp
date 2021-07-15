//成绩大排队
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string tempName, tempNum, maxName, maxNum, minName, minNum;
    int tempScore, maxScore, minScore, n;
    scanf("%d", &n);
    cin >> tempName >> tempNum >> tempScore;
    maxName = minName = tempName;
    maxNum = minNum = tempNum;
    maxScore = minScore = tempScore;
    for (int i = 1; i < n; i++)
    {
        cin >> tempName >> tempNum >> tempScore;
        if (tempScore > maxScore)
        {
            maxName = tempName;
            maxNum = tempNum;
            maxScore = tempScore;
        }
        else if (tempScore < minScore)
        {
            minName = tempName;
            minNum = tempNum;
            minScore = tempScore;
        }
    }
    cout << maxName << " " << maxNum << "\n"
         << minName << " " << minNum << endl;
}