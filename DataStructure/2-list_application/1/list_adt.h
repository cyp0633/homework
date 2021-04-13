//线性表ADT的抽象类声明
#ifndef LIST_ADT_H
#define LIST_ADT_H
template <typename E>
class List
{
private:
    void operator=(const List &) {}
    List(const List &) {} //原来复制构造函数可以放在private……
public:
    List() {}                               //默认构造函数
    virtual ~List() {}                      //析构函数
    virtual void append(const E &item) = 0; //在最后插入元素
    virtual void moveToStart() = 0;         //设定当前位置为表头
    virtual void next() = 0;                //后移一位，最后一位的话不动
    virtual const E &getValue() const = 0;  //返回当前元素
};
#endif