#include <iostream>
void qsort(int arr[], int low, int high);
void Swap(int *a, int *b);
void arrange(int a[], int n);
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    /*  生成数组a  */
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    arrange(a, n);
    /*  函数调用  */
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";

    return 0;
}

void arrange(int a[], int n)
{
    int* p = a, *q = a + n - 1; /*  指针p指向数组的第一个元素，  指针q指向数组的最后一个元素  */

    while (p < q) /*  指针p从左向右寻找第一个偶数，  指针q从右向左寻找第一个奇数，将p、q所指向的元素进行交换，然后指针p、q相向移动  */
    {
        while(*(p)%2==0&&p<a+n-1)
        {
            p++;
        }
        while(*(q)%2==1&&q>a)
        {
            q--;
        }
        if(p<q)
        {
            Swap(p,q);
            p++;
            q--;
        }
    }
    int m = p - a + p - q;
    qsort(a, 0, m);         /*  调用快速排序对奇数部分排序    */
    qsort(a, m + 1, n - 1); /*  调用快速排序对偶数部分排序    */
}

void qsort(int *p, int low, int high)
{
    if (high <= low)
        return;
    int key = p[low];
    int i = low, j = high + 1;
    while (1)
    {
        while (p[++i] < key)
        {
            if (i == high)
                break;
        }
        while (p[--j] > key)
        {
            if (j == low)
                break;
        }
        if (i >= j)
            break;
        Swap(&p[i], &p[j]);
    }
    Swap(&p[low], &p[j]);
    qsort(p, low, j - 1);
    qsort(p, j + 1, high);
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}