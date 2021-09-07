//身份证校验
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, char> veriCode = {{0, '1'}, {1, '0'}, {2, 'X'}, {3, '9'}, {4, '8'}, {5, '7'}, {6, '6'}, {7, '5'}, {8, '4'}, {9, '3'}, {10, '2'}};
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    string id;
    int sum;
    while (cin >> id)
    {
        if (id == "-1")
        {
            return 0;
        }
        sum = 0;
        for (int i = 0; i < 17; i++)
        {
            sum += (id[i] - '0') * weight[i];
        }
        sum %= 11;
        if (id[17] == veriCode[sum])
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}