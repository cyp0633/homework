//内存管理
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct ramblock
{
    int serial = 0;      //编号
    int startPos = 0;    //占用开始位置（含）
    int endPos = 0;      //占用结束位置（含）
    bool erased = false; //是否已经抹除
};
void doAlloc(ramblock r[], const int &m, const int &size, int &x, int &blockNum);
void doErase(ramblock r[], const int &target, int &blockNum);
void doDefragment(ramblock r[], const int &blockNum);
bool compBlock(ramblock a, ramblock b);
int main()
{
    string instruction;
    int t, m, x = 0, param, blockNum = 0; //x从1开始，内存空间也从1开始计算
    ramblock r[502];                      //一直留一个r[0]，编号为0，开始和结束都为0，方便
    scanf("%d%d", &t, &m);
    for (int i = 0; i < t; i++)
    {
        cin >> instruction;
        if (instruction == "alloc")
        {
            cin >> param;
            doAlloc(r, m, param, x, blockNum);
        }
        else if (instruction == "erase")
        {
            cin >> param;
            doErase(r, param, blockNum);
        }
        else
        {
            doDefragment(r, blockNum);
        }
    }
    return 0;
}
void doAlloc(ramblock r[], const int &m, const int &size, int &x, int &blockNum)
{
    x++;
    blockNum++;
    r[blockNum].serial = x;
    for (int i = 1; i < blockNum; i++) //遍历原有结点找空隙
    {
        if (r[i].startPos - r[i - 1].endPos > size)
        {
            r[blockNum].startPos = r[i - 1].endPos + 1;
            r[blockNum].endPos = r[blockNum].startPos + size - 1;
            break;
        }
    }
    if (r[blockNum].endPos == 0) //刚刚没有找到位置插上
    {
        if (m - r[blockNum - 1].endPos < size) //插入失败，空间不足
        {
            x--;
            blockNum--;
            printf("NULL\n");
            return;
        }
        r[x].startPos = r[x - 1].endPos + 1;
        r[x].endPos = r[x].startPos + size - 1;
    }
    sort(r + 1, r + blockNum, compBlock);
    printf("%d\n", x);
    return;
}
void doErase(ramblock r[], const int &target, int &blockNum)
{
    for (int i = 1; i <= blockNum; i++)
    {
        if (r[i].serial == target)
        {
            r[i].erased = true;
            blockNum--;
            sort(r + 1, r + blockNum, compBlock);
            return;
        }
    }
    printf("ILLEGAL_ERASE_ARGUMENT\n"); //没找到
    return;
}
void doDefragment(ramblock r[], const int &blockNum)
{
    int size; //其实并不是真的size，但这样好写省算力
    for (int i = 1; i <= blockNum; i++)
    {
        size = r[i].endPos - r[i].startPos;
        r[i].startPos = r[i - 1].endPos + 1;
        r[i].endPos = r[i].startPos + size;
    }
}
bool compBlock(ramblock a, ramblock b)
{
    if (a.erased)
        return false;
    return a.startPos < b.startPos;
}