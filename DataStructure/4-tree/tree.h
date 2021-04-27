//实验四 二叉树的应用 ADT的实现
#ifndef NODE_H
#define NODE_H
#include "./BinTree.h"
#include <cstdio>
class Node : public BinNode
{
private:
    char value; //值
    Node *leftChild;
    Node *rightChild; //右子节点
public:
    Node() {}
    ~Node() {}
    Node(const char elem)
    {
        value = elem;
        leftChild = rightChild = nullptr;
    }
    char &element()
    {
        return value;
    }
    void setElement(const char &elem)
    {
        value = elem;
    }
    Node *left() const
    {
        return leftChild;
    }
    Node *right() const
    {
        return rightChild;
    }
    void setLeft(Node *left)
    {
        leftChild = left;
    }
    void setRight(Node *right)
    {
        rightChild = right;
    }
    bool isLeaf()
    {
        return leftChild != nullptr && rightChild != nullptr;
    }
    friend class Tree;
};
class Tree : public BinTree
{
private:
    Node *root;
    Node *curr;

public:
    Tree()
    {
        root = curr = nullptr;
        root = build(root);
    }
    Node *build(Node *r)
    {
        char tempLabel;
        tempLabel = getchar();
        if (tempLabel == '#')
        {
            return nullptr;
        }
        r = new Node(tempLabel);
        r->setLeft(build(r->left()));
        r->setRight(build(r->right()));
        return r;
    }
    ~Tree()
    {
        destroy(root);
    }
    void destroy(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        destroy(r->left());
        destroy(r->right());
        delete r;
        return;
    }
    void goRoot()
    {
        curr = root;
    }
    void goLeft()
    {
        curr = curr->left();
    }
    void goRight()
    {
        curr = curr->right();
    }
    char getValue()
    {
        return curr->element();
    }
    void setValue(char &elem)
    {
        curr->setElement(elem);
    }
    void startSearch(char c)
    {
        curr = search(c, root);
    }
    Node *getCurrPtr()
    {
        return curr;
    }
    Node *search(char c, Node *r)
    {
        if (r == nullptr)
        {
            return nullptr;
        }
        if (r->element() == c)
        {
            return r;
        }
        Node *temp = search(c, r->left());
        if (temp != nullptr)
        {
            return temp;
        }
        temp = search(c, r->right());
        if (temp != nullptr)
        {
            return temp;
        }
        return nullptr;
    }
};

#endif