//在Hogwarts找零钱
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
void inputSplit(int &galleon, int &sickle, int &knut);
int main()
{
    string temp;
    int receiveGalleon, receiveSickle, receiveKnut, reqGalleon, reqSickle, reqKnut, changeGalleon, changeSickle, changeKnut;
    inputSplit(reqGalleon, reqSickle, reqKnut);
    inputSplit(receiveGalleon, receiveSickle, receiveKnut);
    changeGalleon = receiveGalleon - reqGalleon;
    changeSickle = receiveSickle - reqSickle;
    changeKnut = receiveKnut - reqKnut;
    if (changeGalleon < 0 || (changeGalleon == 0 && changeSickle < 0) || (changeGalleon == 0 && changeSickle == 0 && changeKnut < 0))
    {
        changeGalleon *= -1;
        changeSickle *= -1;
        changeKnut *= -1;
        putchar('-');
    }
    if (changeKnut < 0)
    {
        changeKnut += 29;
        changeSickle -= 1;
    }
    if (changeSickle < 0)
    {
        changeSickle += 17;
        changeGalleon -= 1;
    }
    printf("%d.%d.%d", changeGalleon, changeSickle, changeKnut);
    return 0;
}
void inputSplit(int &galleon, int &sickle, int &knut)
{
    string temp;
    cin >> temp;
    size_t firstDot, secDot;
    firstDot = temp.find('.');
    secDot = temp.find('.', firstDot + 1);
    galleon = stoi(temp.substr(0, firstDot));
    sickle = stoi(temp.substr(firstDot + 1, secDot - firstDot - 1));
    knut = stoi(temp.substr(secDot + 1, temp.length() - secDot - 1));
}