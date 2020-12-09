#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    n = n - ceil(1.00 * y / x);
    if (n < 0)
    {
        printf("0");
        return 0;
    }
    cout << n;
    return 0;
}