//实验四 二叉树的应用 ADT的定义与声明
#ifndef BINTREE_H
#define BINTREE_H
template <typename E>
class BinNode
{
    virtual ~BinNode() {}
    virtual E &element() = 0;
    virtual void setElement(const E &) = 0; //设置值
    virtual BinNode *left() const = 0;      //左子节点指针
    virtual BinNode *right() const = 0;     //右子节点指针
    virtual void setLeft(BinNode *) = 0;    //设置左子节点
    virtual void setRight(BinNode *) = 0;   //设置右子节点
    virtual bool isLeaf() = 0;              //是否为叶子节点
};
template <typename E>
class BinTree
{

public:
    virtual BinTree() = 0;                      //构造函数启动建树
    virtual void build(BinNode<E> *root) = 0;   //递归建树过程
    virtual ~BinTree() = 0;                     //析构函数
    virtual void destroy(BinNode<E> *root) = 0; //析构时释放所用
    virtual void goLeft() = 0;                  //切换到左子节点
    virtual void goRight() = 0;                 //切换到右子节点
    virtual void getValue() = 0;                //获得结点名称
    virtual E setValue(E &) = 0;             //设置结点名称
    virtual void setLeft() = 0;                 //设置左子节点
    virtual void setRight() = 0;                //设置右子节点
    virtual void goRoot() = 0;                  //返回根节点
};
#endif