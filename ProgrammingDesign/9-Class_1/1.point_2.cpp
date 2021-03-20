//Point类的设计与实现
#include <iostream>
#include <cmath> //声明sqrt函数
using namespace std;
class Point //完成Point类的声明，包含数据成员和成员函数
{
private:
    int x;
    int y;
    //  成员函数原型声明
public:
    void setPoint();
    int getX() const;
    int getY() const;
    // double myDistance(int xVal,int yVal);
};
void Point::setPoint() //从键盘输入Point的坐标
{
    cin >> x >> y;
}
int Point::getX() const //获得X坐标
{
    return x;
}
int Point::getY() const //获得Y坐标
{
    return y;
}
void myDistance(int xVal, int yVal) //计算两个点的距离，并输出
{
    double a = sqrt(pow(xVal, 2) + pow(yVal, 2));
    int b = round(a * 1000);
    a = b / 1000.0;
    printf("%.3f",a);
}
int main()
{
    Point A, B; //定义两个Point对象，A和B;
                //从键盘输入A和B的坐标
    A.setPoint();
    B.setPoint();
    //输出A和B之间的距离

    myDistance(A.getX() - B.getX(), A.getY() - B.getY());
    return 0;
}