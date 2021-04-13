//链表实现
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
    Link(const E &elemval, Link *nextval = nullptr)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = nullptr)
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
        while (head != nullptr)
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
    void clear()
    {
        removeall();
        init(); //可能是因为这个
    }
    bool empty()
    {
        if (head == tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(const E &it) //插入元素
    {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr)
        {
            tail = curr->next;
        }
        cnt++;
    }
    void append(const E &it) //在最后添加元素
    {
        tail = tail->next = new Link<E>(it, nullptr);
        cnt++;
    }
    E remove() //移除当前位置后一个的元素
    {
        //Assert(curr->next!=NULL,"No Element");
        E it = curr->next->element;
        Link<E> *ltemp = curr->next;
        if (tail == curr->next) //被删除的元素是tail的情况
        {
            tail = curr;
        }
        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
        return it;
    }
    void moveToStart() //移至头部
    {
        curr = head;
    }
    void moveToEnd() //移至尾部。这里应该有点问题，curr要读取tail的指针，应该向前一位。
    {
        curr = tail;
        prev();
    }
    void prev() //左移一位。单向链表只能从左边一个一个移过来
    {
        if (curr == head)
        {
            return;
        }
        Link<E> *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
    void next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }
    int length() const
    {
        return cnt;
    }
    int currPos() const
    {
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
        {
            temp = temp->next;
        }
        return i;
    }
    void moveToPos(int pos)
    {
        //Assert((pos>=0)&&(pos<=cnt),"Position Out of Range");
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }
    const E &getValue() const
    {
        //Assert(curr->next!=NULL,"No Value");
        return curr->next->element; //对，curr确实是前驱
    }
    void reverse() //链表反转
    {
        Link<E> *newTail, *newHead, *temp;
        head = head->next;
        newHead = newTail = head;
        head = head->next;
        for (int i = 1; i < length(); i++)
        {
            temp = head;
            head = head->next;
            temp->next = newHead;
            newHead = temp;
        }
        newHead = new Link<E>(newHead);
        head = newHead;
        tail = newTail;
    }
};
#endif