//快速排序
#include <cstdio>
#include <iostream>
using namespace std;
void quicksort(int num[], const int &l, const int &r);
template <typename T>
void swap(T *a, T *b);
int getPivot(int num[], const int &l, const int &r);
bool checkOrder(int num[], const int &l, const int &r);
int main()
{
    int num[100000], n, a;
    scanf("%d", &n);
    for (a = 0; a < n; a++)
    {
        scanf("%d", &num[a]);
    }
    quicksort(num, 0, n - 1);
    for (a = 0; a < n; a++)
    {
        printf("%d ", num[a]);
    }
    return 0;
}
void quicksort(int num[], const int &l, const int &r) //数组，左边界，右边界
{
    if (l >= r) //区间不可再排序
    {
        return;
    }
    if (checkOrder(num, l, r)) //这个区间是有序的
    {
        printf("Ordered between %d and %d, returning...");
        return;
    }
    int i, j, pivotpos = getPivot(num, l, r);
    int pivot = num[pivotpos];
    printf("L=%d R=%d\n", l, r);
    printf("Pivot selected: %d\n", pivot);
    swap(num + l, num + pivotpos);
    i = l;
    j = r;
    while (i < j)
    {
        while (num[j] >= pivot && i < j) //移到右边第一个比pivot小的数
        {
            j--;
        }
        while (num[i] <= pivot && i < j) //移到左边第一个比pivot大的数
        {
            i++;
        }
        if (i < j)
        {
            swap(num + i, num + j);
            printf("Swapped %d and %d\n", num[j], num[i]);
        }
    }
    swap(num + l, num + i);
    printf("Swapped %d and %d\n", num[i], num[l]);
    quicksort(num, l, i - 1);
    quicksort(num, i + 1, r);
    return;
}
template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int getPivot(int num[], const int &l, const int &r)
{
    pair<int, int> lVal(num[l], l);
    pair<int, int> rVal(num[r], r);
    pair<int, int> midVal(num[(l + r) / 2], (l + r) / 2);
    if (rVal > midVal)
    {
        swap(&rVal, &midVal);
    }
    if (midVal > lVal)
    {
        swap(&lVal, &midVal);
    }
    if (rVal > midVal)
    {
        swap(&rVal, &midVal);
    }
    return midVal.second;
}
bool checkOrder(int num[], const int &l, const int &r)
{
    for (int i = l; i < r; i++)
    {
        if (num[i] > num[i + 1])
        {
            return false;
        }
    }
    return true;
}