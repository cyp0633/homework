//公共钥匙盒 CCF 201709-2
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Operation
{
public:
    int time;
    bool type; //0是借，1是还
    int keyNum;
    Operation(int a, int b, int c) : time(a), type(b), keyNum(c) {}
    Operation() {}
};
bool operator>(const Operation &a, const Operation &b) //重载greater运算符
{
    if (a.time != b.time)
    {
        return a.time > b.time;
    }
    if (a.type != b.type)
    {
        return a.type < b.type;
    }
    return a.keyNum > b.keyNum;
}
int main()
{
    int i, n, k;
    int tempBorrowTime, tempKeynum, tempReturnTime;
    int keychain[10000] = {-1}; //没有钥匙就是-1
    Operation temp;
    priority_queue<Operation, vector<Operation>, greater<Operation>> operationQueue; //生成一个小顶堆
    cin >> n >> k;
    for (i = 0; i < n; i++) //放置钥匙
    {
        keychain[i] = i + 1;
    }
    for (i = 0; i < k; i++)
    {
        cin >> tempKeynum >> tempBorrowTime >> tempReturnTime;
        tempReturnTime += tempBorrowTime;
        operationQueue.push(Operation(tempBorrowTime, 0, tempKeynum));
        operationQueue.push(Operation(tempReturnTime, 1, tempKeynum));
    }
    while (!operationQueue.empty())
    {
        if (operationQueue.top().type == 1) //还
        {
            for (i = 0; i < n; i++)
            {
                if (keychain[i] == -1)
                {
                    keychain[i] = operationQueue.top().keyNum;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (keychain[i] == operationQueue.top().keyNum)
                {
                    keychain[i] = -1;
                    break;
                }
            }
        }
        operationQueue.pop();
    }
    for (i = 0; i < n; i++)
    {
        cout << keychain[i] << ' ';
    }
    return 0;
}