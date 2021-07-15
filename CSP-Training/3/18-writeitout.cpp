//写出来吧
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string n, sumStr, chinese[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int sum = 0;
    cin >> n;
    for (string::iterator it = n.begin(); it != n.end(); ++it)
    {
        sum += *it - '0';
    }
    sumStr = to_string(sum);
    for (string::iterator it = sumStr.begin(); it != sumStr.end(); ++it)
    {
        cout << chinese[*it - '0'] << ' ';
    }
    return 0;
}