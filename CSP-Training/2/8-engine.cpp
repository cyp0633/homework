//Engine HDU 2532
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
class paper
{
public:
    string name;
    string keyword[10];
    int keywordNum; //记得初始化这个！
    int refer;
    void splitKeyword();
};
bool compPaper(const paper &a, const paper &b);
string low(const string &s);
int main()
{
    paper p[1000];
    int n, m, reqNum, k, q;
    string reqTemp[10];
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        getchar();
        for (int i = 0; i < n; i++)
        {
            getline(cin, p[i].name);
            scanf("%d", &p[i].refer);
            getchar();
            p[i].splitKeyword();
        }
        stable_sort(p, p + n, compPaper);
        scanf("%d", &m);
        getchar();
        for (int i = 0; i < m; i++)
        {
            reqNum = 0;
            while (cin.peek() != '\n')
            {
                cin >> reqTemp[reqNum];
                reqTemp[reqNum] = low(reqTemp[reqNum]);
                reqNum++;
            }
            for (int j = 0; j < n; j++) //遍历文献目录
            {
                for (k = 0; k < reqNum; k++) //遍历关键词列表
                {
                    for (q = 0; q < p[j].keywordNum; q++)
                    {
                        if (reqTemp[k] == p[j].keyword[q])
                        {
                            break;
                        }
                    }
                    if (q == p[j].keywordNum) //遍历完了，没找到
                    {
                        break;
                    }
                }
                if (k == reqNum)
                {
                    cout << p[j].name << '\n';
                }
            }
            printf("***\n");
            getchar();
        }
        printf("---\n");
    }
    return 0;
}
bool compPaper(const paper &a, const paper &b)
{
    return a.refer > b.refer;
}
string low(const string &s)
{
    string str;
    for (string::const_iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i >= 'A' && *i <= 'Z')
        {
            str.push_back(*i - 'A' + 'a');
        }
        else
        {
            str.push_back(*i);
        }
    }
    return str;
}
void paper::splitKeyword()
{
    stringstream s;
    keywordNum = 0;
    s << low(name);
    while (s.rdbuf()->in_avail() != 0) //这个是判空
    {
        s >> keyword[keywordNum];
        keywordNum++;
    }
}