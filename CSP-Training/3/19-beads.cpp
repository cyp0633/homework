//到底买不买
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count[200], require[200], lack, spare;
    string want, candidate;
    cin >> candidate >> want;
    memset(count, 0, sizeof(count));
    memset(require, 0, sizeof(require));
    lack = 0;
    spare = 0;
    for (string::iterator i = candidate.begin(); i != candidate.end(); i++)
    {
        count[(int)*i]++;
    }
    for (string::iterator i = want.begin(); i != want.end(); i++)
    {
        require[(int)*i]++;
    }
    for (int i = 0; i < 200; i++)
    {
        if (count[i] < require[i])
        {
            lack += require[i] - count[i];
        }
        else
        {
            spare += count[i] - require[i];
        }
    }
    if (lack == 0)
    {
        printf("Yes %d\n", spare);
    }
    else
    {
        printf("No %d\n", lack);
    }
}