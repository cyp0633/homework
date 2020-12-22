#include<cstdio>
#include<iostream>
using namespace std;
template <class numtype>
class Node
{
    public:
    numtype value;
    Node getNext()
    {
        return next;
    }
    void setNext(Node* nxt)
    {
        next=nxt;
        return;
    }
    Node(int v):value(v),next(NULL){}
    Node():next(NULL){}
    private:
    Node* next;
};
template <class numtype>
class List
{
    public:
    List():start(NULL),end(NULL){}
    void insert(numtype value,int position)//插入数据
    {
        Node<numtype>* newNode=new Node<numtype>(value);
        if(start==NULL)
        {
            printf("ERROR. List is empty.\n");
        }
        Node<numtype>* temp=start,tempNext;
        for(int i=1;i<position;i++)
        {
            temp=temp->getNext();
        }
        tempNext=temp->getNext();
        temp->setNext(newNode);
        newNode.setNext(tempNext);
    }
    int length()//计算长度
    {
        if(start==NULL)
        {
            return 0;
        }
        int len=1;
        Node<numtype>* pos=start;
        while(pos->getNext()!=NULL)
        {
            len++;
            pos=pos->getNext();
        }
        return len;
    }
    void del(int pos)//删除元素
    {
        Node<numtype>* temp=start,tempNext;
        for(int i=1;i<pos;i++)
        {
            temp=temp->getNext();
            if(temp->getNext()==NULL)
            {
                printf("ERROR: Not enough elements");
            }
        }
        tempNext=temp->getNext()->getNext();
        delete temp->getNext();
        temp->setNext(tempNext);
        return;
    }
    private:
    Node<numtype>* start;
    Node<numtype>* end;
};
int main()
{
    List<int> list1;
    return 0;
}