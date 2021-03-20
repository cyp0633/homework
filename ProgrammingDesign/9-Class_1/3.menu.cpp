//菜单类的设计与实现
#include <iostream>
using namespace std;

class menu
{
public:
    menu();
    void setItems(int n)
    {
        string a;
        num=n;
        item=new string[n];
        for(int i=0;i<n;i++)
        {
            getline(cin,a);
            *(item+i)=a;
        }
        return;
    }
    ~menu()
    {
        delete item;
    }
    void show()
    {
        for(int i=0;i<num;i++)
        {
            cout<<*(item+i)<<'\n';
        }
        return;
    }
private:
    int num;
    string *item;
};
menu::menu()
{
    num = 0;
    item = NULL;
}

int main()
{
    menu caidan; //声明菜单类对象
    int n;
    cin >> n;
    cin.get();          //吸收整数输入后的回车
    caidan.setItems(n); //从键盘输入菜单对象的n个菜单项
    caidan.show();      //输出菜单对象的n个菜单项
    return 0;
}
