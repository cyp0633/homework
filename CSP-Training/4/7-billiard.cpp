//斯诺克台球
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    int T; //测试数据组数
    scanf("%d", &T);
    getchar();
    const map<char, int> score = {{'r', 1}, {'y', 2}, {'g', 3}, {'c', 4}, {'b', 5}, {'p', 6}, {'B', 7}, {'A', 0}}; //每种球击入得分
    const string stage2Order = "ygcbpB";                                                                           //第二阶段击球顺序
    int singlePostExceed100[2] = {0};                                                                              //单杆超过100分计数
    while (T--)
    {
        map<char, int> ball = {{'r', 15}, {'y', 1}, {'g', 1}, {'c', 1}, {'b', 1}, {'p', 1}, {'B', 1}}; //每种球剩余数量
        int singlePostScore,                                                                           //单杆得分
            currentHiter = 0,                                                                          //当前击球人，0=a，1=b
            score[2] = {0},                                                                            //本局得分
            currentStage = 0,                                                                          //当前阶段，0=打红球，1=打彩球
            maxPenalty;                                                                                //若犯规了的最高相关球分数
        char targetBall;                                                                               //本轮目标球,'A'=任意彩球，不含红球
        bool isPenalty;                                                                                //是否犯规
        stringstream tempStream;
        string tempStr;
        size_t blankPos; //空格分隔符的位置
        while (1)
        {
            isPenalty = false; //初始化
            maxPenalty = 0;
            singlePostScore = 0;
            getline(cin, tempStr);
            if (tempStr == "-1") //结算
            {
                printf("%d:%d\n", score[0], score[1]);
                break;
            }
            if (tempStr == "NULL") //没击中犯规
            {
                currentHiter = 1 ^ currentHiter;                                      //交换次序
                score[currentHiter] += score[targetBall] > 4 ? score[targetBall] : 4; //加分。这里假定任意彩球对应分数是0
            }
            blankPos = tempStr.find(' ');
            for (string::iterator i = tempStr.begin(); i != tempStr.end() && i != tempStr.begin() + blankPos; i++) //遍历首先碰到的球
            {
                if ((*i != targetBall && targetBall != 'A') || (targetBall == 'A' && *i == 'r')) //非任意彩球打进了其他球，或者任意彩球打进了红球，都犯规
                {
                    isPenalty = true;
                    maxPenalty = score[*i] > maxPenalty ? score[*i] : maxPenalty;
                }
            }
            if (isPenalty)
            {
                if (blankPos != string::npos)
                {
                    for (string::iterator i = tempStr.begin() + blankPos + 1; i != tempStr.end(); i++)
                    {
                        if ((*i != targetBall && targetBall != 'A') || (targetBall == 'A' && *i == 'r'))
                        {
                            maxPenalty = score[*i] > maxPenalty ? score[*i] : maxPenalty;
                        }
                    }
                }

                currentHiter = 1 ^ currentHiter;
                score[currentHiter] += maxPenalty > 4 ? maxPenalty : 4;
            }
            if (currentStage == 0) //打红球的阶段
            {
            }
        }
    }
    printf("%d:%d", singlePostExceed100[0], singlePostExceed100[1]);
    return 0;
}
//TODO:切换目标球，统计红球进洞数量，阶段切换，无犯规过程的计分