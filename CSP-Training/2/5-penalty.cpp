//点球大战
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, score[2]; //先罚的是0，然后是1
    string board[2], temp;
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        getchar();
        score[0] = score[1] = 0;
        board[0] = board[1] = "";
        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);
            if (temp.find("no good") == string::npos) //进了
            {
                score[i % 2]++;
                board[i % 2].push_back('O');
            }
            else
            {
                board[i % 2].push_back('X');
            }
            board[i % 2].push_back(' ');
        }
        if (board[1].length() < board[0].length())
        {
            board[1].push_back('-');
            board[1].push_back(' ');
        }
        for (int i = 1; i <= board[0].length() / 2; i++)
        {
            printf("%d ", i);
        }
        printf("Score\n");
        cout << board[0] << score[0] << '\n';
        cout << board[1] << score[1] << '\n';
    }
    return 0;
}