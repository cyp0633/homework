//实验四 二叉树的应用 ADT的实现
#ifndef NODE_H
#define NODE_H
#include "./BinTree.h"
#include <cstdio>
template <typename E>
class Node : public BinNode<E>
{
private:
    E value;                        //值
    Node<E> *leftChild;
    Node<E>* rightChild; //右子节点
public:
    Node() {}
    Node(const E elem)
    {
        value = elem;
        leftChild=rightChild=nullptr;
    }
    E &element()
    {
        return value;
    }
    void setElement(const E &elem)
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
    void setLeft(Node<E> *left)
    {
        leftChild = left;
    }
    void setRight(Node<E> *right)
    {
        rightChild = right;
    }
    bool isLeaf()
    {
        return leftChild != nullptr && rightChild != nullptr;
    }
    friend class Tree<E>;
};
template <typename E>
class Tree : public BinTree<E>
{
private:
    Node<E> *root;
    Node<E> *curr;

public:
    Tree()
    {
        root=curr=nullptr;
        build(root);
    }
    void build(BinNode<E>* root)
    {
        char tempLabel;
        tempLabel=getchar();
        if(tempLabel=='#')
        {
            return;
        }
        root=new Node<E>(tempLabel);
        build(root->left());
        build(root->right());
    }
    ~Tree()
    {
        destroy(root);
    }
    void destroy(BinNode<E>* root)
    {
        if(root==nullptr)
        {
            return;
        }
        destroy(root->left());
        destroy(root->right());
        delete root;
        return;
    }
    void goRoot()
    {
        curr=root;
    }
    void goLeft()
    {
        curr=curr->left();
    }
    void goRight()
    {
        curr=curr->right();
    }
    E getValue()
    {
        return curr->element();
    }
    void setValue()
    {
        curr
    }
};
#endif