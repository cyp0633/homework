//小希练打字
#include <cstdio>
#include <iostream>
using namespace std;
bool ifLeft(char k);

int main()
{
    int i, j, len, n, tCount = 0, timeStore[1000];
    bool keyPlace[1000], x;
    scanf("%d\n", &n);
    string word, wordStore[1000];
    for (i = 0; i < n; i++)
    {
        x = false;
        timeStore[i] = 2;
        getline(cin, wordStore[i]);
        len = wordStore[i].length();
        for (j = 0; j < i; j++)
        {
            if (wordStore[j] == wordStore[i])
            {
                x = true;
                tCount += timeStore[j] / 2;
                break;
            }
        }
        if (x)
        {
            continue;
        }
        for (j = 0; j < len; j++)
        {
            keyPlace[j] = ifLeft(wordStore[i][j]);
        }
        for (j = 1; j < len; j++)
        {
            if (keyPlace[j - 1] == keyPlace[j])
            {
                timeStore[i] += 4;
            }
            else
            {
                timeStore[i] += 2;
            }
        }
        tCount += timeStore[i];
    }
    printf("%d", tCount);
    return 0;
}
bool ifLeft(char k)
{
    if (k <= 'Z')
    {
        k += 'a' - 'A';
    }
    if (k == 'q' || k == 'w' || k == 'e' || k == 'r' || k == 't' || k == 'a' || k == 's' || k == 'd' || k == 'f' || k == 'g' || k == 'z' || k == 'x' || k == 'c' || k == 'v' || k == 'b')
    {
        return true;
    }
    else
    {
        return false;
    }
}