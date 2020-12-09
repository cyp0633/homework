//书籍类的设计与实现
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Book
{
public:
    Book();
    void setInfo()
    {
        shelf_id = new char[18];
        gets(shelf_id);
        scanf("%f\n",&price);
        return;
    }
    void show()
    {
        cout << "Shelf_ID: " << fixed << setw(18) << left << shelf_id;
        cout.unsetf(ios::fixed);
        cout << "Price: " << price << '\n';
    }
private:
    float price;
    char *shelf_id;
};
Book::Book()
{
    price = 0;
    shelf_id = NULL;
}

int main()
{
    int n;
    cin >> n;        //从键盘输入整数n
    cin.get();       //吸收整数输入后的回车
    Book library[n]; //声明对象数组
    for (int i = 0; i < n; i++)
    {
        library[i].setInfo(); //从键盘输入对象数组的每个元素
    }
    for (int i = 0; i < n; i++)
    {
        library[i].show(); //输出对象数组
    }
    return 0;
}