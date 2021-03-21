//链表实现
#include <cstddef>
#include "list_adt.h"
#ifndef LINK
#define LINK
#define defaultsize 65536;
template <typename E>
class Link //node的实现
{
public:
    E element;
    Link *next;
    Link(const E &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};
#endif
#ifndef LINKLIST_H
#define LINKLIST_H
template <typename E>
class LList : public List<E>
{
private:
    Link<E> *head; //头指针
    Link<E> *tail; //尾指针
    Link<E> *curr; //其实应该是现位置的前驱节点，方便插入与删除等操作
    int cnt;       //链表长度
    void init()    //初始化链表
    {
        curr = tail = head = new Link<E>; //第一个元素没啥用，它的next才是真正的"第一个元素"
        cnt = 0;
    }
    void removeall() //删除所有元素
    {
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size = 65536) //构造。与public隔离，public中只能调用构造函数
    {
        init();
    }
    ~LList() //析构。同样不知道为啥要写一个removeall
    {
        removeall();
    }
    void append(const E &it) //在最后添加元素
    {
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
    void moveToStart() //移至头部
    {
        curr = head;
    }
    void next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }
    const E &getValue() const
    {
        return curr->next->element;
    }
    Link<E>* getNext() const
    {
        return curr->next->next;
    }
};
#endif