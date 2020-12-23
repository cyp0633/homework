//文件排版（文本文件读写）
#include <cstdio>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    int commaPos;
    string::size_type colonPos;
    string tmp;
    string postList, castList;
    scanf("%d\n", &commaPos);
    freopen("listin.txt", "r", stdin);
    freopen("listout.txt", "w", stdout);
    while (getline(cin, tmp))
    {
        stringstream ss;
        postList = "";
        castList = "";
        ss.str(tmp);
        while (ss >> tmp)
        {
            if (tmp == ":")
            {
                break;
            }
            colonPos = tmp.find(':');
            if (colonPos != string::npos)
            {
                if (colonPos != 0)
                {
                    postList += tmp.substr(0, colonPos) + ' ';
                }
                if (colonPos + 1 != tmp.length())
                {
                    castList += tmp.substr(colonPos + 1, tmp.length()) + ' ';
                }
                break;
            }
            else
            {
                postList += tmp + ' ';
            }
        }
        while (ss >> tmp)
        {
            castList += tmp + ' ';
        }
        cout << setw(commaPos - 1) << left << postList << ": " << castList << '\n';
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}