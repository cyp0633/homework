//学生类的设计与实现
#include <iostream>
#include <string>
#include <iomanip> //输出控制
using namespace std;
class Student //Student类型声明
{
private:
    string name;
    double grade;

public:
    Student()
    {
        cin >> name >> grade;
    }
    bool output()
    {
        if (grade >= 60.0)
        {
            cout << fixed << setw(11) <<left<< name << ' ' << setprecision(1) << grade << '\n';
            return true;
        }
        else
        {
            return false;
        }
    }
};
void pass(Student *pStu, int size) //pass函数定义
{
    bool exist=false;
    for (int i = 0; i < size; i++)
    {
        if((pStu + i)->output())
        {
            exist=true;
        }
    }
    if(!exist)
    {
        cout<<"not exist";
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    Student *stu = new Student[n]; //动态分配内存给n个Student对象
    pass(stu, n);                  //调用pass函数，以指针stu作为函数参数
    delete[] stu;                  //释放动态内存
    return 0;
}