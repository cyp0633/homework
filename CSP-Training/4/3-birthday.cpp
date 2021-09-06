//相同生日
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> birthday[13][32];
    int mon, day;
    string id;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> mon >> day;
        birthday[mon][day].push_back(id);
    }
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 31; j++)
        {
            if (birthday[i][j].size() > 0)
            {
                printf("%d %d", i, j);
                for (vector<string>::iterator k = birthday[i][j].begin(); k != birthday[i][j].end(); k++)
                {
                    cout << ' ' << *k;
                }
                putchar('\n');
            }
        }
    }
    return 0;
}