#include <algorithm>
#include <iostream>
using namespace std;
void swap(int &a, int &b) //这部分源程序没有，不知道咋运行
{
    int c = a;
    a = b;
    b = c;
}
inline int findpivot(int *A, int i, int j)
{
    return (i + j) / 2;
}
inline int Partition(int *A, int left, int right, int &pivot)
{
    do
    {
        while (A[++left] < pivot)
            ;
        while ((left < right) && (pivot < A[--right]))
            ;
        swap(A[left], A[right]);
    } while (left < right);
    return left;
}
void qsort(int *A, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivotIndex = findpivot(A, left, right);
    swap(A[pivotIndex], A[right]);
    int k = Partition(A, left - 1, right, A[right]);
    swap(A[k], A[right]);
    qsort(A, left, k - 1);
    qsort(A, k + 1, right);
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a;
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}