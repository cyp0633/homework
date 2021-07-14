//占座位
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct occupation
{
    int startPos = 0;
    int endPos = 0;
    int ownerId = 0;
    bool isFree = false;
} o[100];
bool requested[100];
void occupy(const int &requestSize, int &currentOccupationNum, const int &ownerId, const int &n);
void free(const int ownerId, int &currentOccupationNum);
void insertSort(const int &occupationNum);
bool compOccupation(const occupation &a, const occupation &b);
int main()
{
    memset(requested, 0, sizeof(requested));
    int m, n, k, requestId, requestSize, currentOccupationNum = 0;
    string command;
    scanf("%d %d %d", &n, &m, &k);
    n *= n;
    for (int i = 0; i < k; i++)
    {
        cin >> command >> requestId;
        if (command == "in")
        {
            cin >> requestSize;
            if (requested[requestId])
            {
                printf("no\n");
            }
            else
            {
                occupy(requestSize, currentOccupationNum, requestId, n);
            }
        }
        else
        {
            if (!requested[requestId])
            {
                printf("no\n");
            }
            else
            {
                free(requestId, currentOccupationNum);
            }
        }
    }
    return 0;
}
void occupy(const int &requestSize, int &currentOccupationNum, const int &ownerId, const int &n)
{
    currentOccupationNum++;
    o[currentOccupationNum].ownerId = ownerId;
    o[currentOccupationNum].endPos = 0;
    for (int i = 1; i < currentOccupationNum; i++)
    {
        if (o[i].startPos - o[i - 1].endPos > requestSize)
        {
            o[currentOccupationNum].startPos = o[i - 1].endPos + 1;
            o[currentOccupationNum].endPos = o[currentOccupationNum].startPos + requestSize - 1;
            break;
        }
    }
    if (o[currentOccupationNum].endPos == 0)
    {
        if (n - o[currentOccupationNum - 1].endPos < requestSize)
        {
            currentOccupationNum--;
            printf("no\n");
            return;
        }
        o[currentOccupationNum].startPos = o[currentOccupationNum - 1].endPos + 1;
        o[currentOccupationNum].endPos = o[currentOccupationNum].startPos + requestSize - 1;
    }
    o[currentOccupationNum].isFree = false;
    printf("yes\n");
    requested[ownerId] = true;
    insertSort(currentOccupationNum);
    return;
}
void free(const int ownerId, int &currentOccupationNum)
{
    for (int i = 1; i <= currentOccupationNum; i++)
    {
        if (o[i].ownerId == ownerId)
        {
            o[i].isFree = true;
            currentOccupationNum--;
            insertSort(currentOccupationNum + 1);
            printf("yes\n");
            requested[ownerId] = false;
            return;
        }
    }
    printf("no\n");
    return;
}
void insertSort(const int &occupationNum) //insert sort occupation from 2 to occupationNum
{
    for (int i = 2; i <= occupationNum; i++)
    {
        occupation key = o[i];
        int j = i - 1;
        while (j > 0 && !compOccupation(o[j], key))
        {
            o[j + 1] = o[j];
            j--;
        }
        o[j + 1] = key;
    }
}
bool compOccupation(const occupation &a, const occupation &b)
{
    if (a.isFree)
    {
        return false;
    }
    return a.startPos < b.startPos;
}