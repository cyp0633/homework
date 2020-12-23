//文件排版（文本文件读写）
#include<cstdio>
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;

int main() {
    int commaPos;
    string tmp;
    string postList, castList;
    scanf("%d\n", &commaPos);
    freopen("listin.txt", "r", stdin);
    freopen("listout.txt", "w", stdout);
    while (getline(cin, tmp)) {
        stringstream ss;
        postList = "";
        castList = "";
        ss.str(tmp);
        while (ss >> tmp) {
            if (tmp == ":") {
                break;
            }
            if (tmp[tmp.length() - 1] == ':') {
                tmp.pop_back();
                postList += tmp + ' ';
                break;
            } else {
                postList += tmp + ' ';
            }
        }
        while (ss >> tmp) {
            castList += tmp + ' ';
        }
        cout << setw(commaPos) << left << postList << ": " << castList << '\n';
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}