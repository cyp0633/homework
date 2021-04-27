//实验四 二叉树的应用 ADT的定义与声明
#ifndef BINTREE_H
#define BINTREE_H
class BinNode
{
public:
    virtual ~BinNode() {}
    virtual char &element() = 0;
    virtual void setElement(const char &) = 0; //设置值
    virtual BinNode *left() const = 0;         //左子节点指针
    virtual BinNode *right() const = 0;        //右子节点指针
    virtual bool isLeaf() = 0;                 //是否为叶子节点
};
class BinTree
{

public:
    virtual void goLeft() = 0;         //切换到左子节点
    virtual void goRight() = 0;        //切换到右子节点
    virtual char getValue() = 0;       //获得结点名称
    virtual void setValue(char &) = 0; //设置结点名称
    virtual void goRoot() = 0;         //返回根节点
};
#endif