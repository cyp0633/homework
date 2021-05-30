#include <algorithm>
#include <iostream>
using namespace std;

void mergesort(int *A, int *temp, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergesort(A, temp, left, mid);
    mergesort(A, temp, mid + 1, right);
    for (int i = left; i <= right; i++) //memcpy?先将数字加进temp区域
    {
        temp[i] = A[i];
    }
    int i1 = left;
    int i2 = mid + 1;
    for (int curr = left; curr <= right; curr++) //只是一个计数器，放回一个数字加一个
    {
        if (i1 == mid + 1) //左半边的数字消耗完毕，加右边的
        {
            A[curr] = temp[i2++];
        }
        else if (i2 > right) //右半边的数字消耗完毕，加左边的
        {
            A[curr] = temp[i1++];
        }
        else if (temp[i1] < temp[i2]) //左边的小，加左边的
        {
            A[curr] = temp[i1++];
        }
        else //右边的小，加右边的
        {
            A[curr] = temp[i2++];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a, *temp;
    a = new int[n];
    temp = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, temp, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}