//实验三模拟测试 基于二叉链表的二叉树实现
#include "string"
#include <iostream>
#include <queue>

using namespace std;

template <typename E>
class BinNode //结点类
{
private:
    BinNode *lc; //左孩子
    BinNode *rc; //右孩子
    E elem;

public:
    BinNode() //默认构造函数，设置左右孩子为空
    {
        lc = rc = nullptr;
    }
    BinNode(E tmp, BinNode *l = NULL, BinNode *r = NULL) //带参构造函数
    {
        elem = tmp;
        lc = l;
        rc = r;
    }
    BinNode *left() //返回左孩子
    {
        return lc;
    }
    BinNode *right() //返回右孩子
    {
        return rc;
    }
    void setLeft(BinNode *l) //设置左孩子
    {
        lc = l;
    }
    void setRight(BinNode *r) //设置右孩子
    {
        rc = r;
    }
    void setValue(E tmp) //设置当前结点的值
    {
        elem = tmp;
    }
    E getValue() //获得当前结点的值
    {
        return elem;
    }
    bool isLeaf() //判断当前结点是否为叶子结点
    {
        if (lc == nullptr && rc == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template <typename E>
class BinTree //二叉树类
{
private:
    BinNode<E> *root;         //根结点
    void clear(BinNode<E> *r) //清空二叉树
    {
        if (r == nullptr)
        {
            return;
        }
        clear(r->left());
        clear(r->right());
        delete r;
    }
    void preOrder(BinNode<E> *tmp, void (*visit)(BinNode<E> *node)) //先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {
        if (tmp == nullptr)
        {
            return;
        }
        (*visit)(tmp);
        preOrder(tmp->left(), visit);
        preOrder(tmp->right(), visit);
    }
    void inOrder(BinNode<E> *tmp, void (*visit)(BinNode<E> *node)) //中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {
        if (tmp == nullptr)
        {
            return;
        }
        inOrder(tmp->left(), visit);
        (*visit)(tmp);
        inOrder(tmp->right(), visit);
    }
    void postOrder(BinNode<E> *tmp, void (*visit)(BinNode<E> *node)) //后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {
        if (tmp == nullptr)
        {
            return;
        }
        postOrder(tmp->left(), visit);
        postOrder(tmp->right(), visit);
        (*visit)(tmp);
    }
    void LevelOrderTranverse(BinNode<E> *tmp, void (*visit)(BinNode<E> *node)) //层次遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {
        if(tmp==nullptr)
        {
            return;
        }
        queue<BinNode<E> *> visitQueue;
        visitQueue.push(tmp);
        BinNode<E> *curr;
        while (!visitQueue.empty())
        {
            curr = visitQueue.front();
            visitQueue.pop();
            if (curr->left() != nullptr)
            {
                visitQueue.push(curr->left());
            }
            if (curr->right() != nullptr)
            {
                visitQueue.push(curr->right());
            }
            (*visit)(curr);
        }
    }
    int BinTreeHeight(BinNode<E> *tmp) //获得二叉树的深度
    {
        if(tmp==nullptr) return 0;
        return BinTreeDepth(tmp)-1;
    }
    int BinTreeNodes(BinNode<E> *tmp) //获得二叉树的结点数
    {
        if (tmp == nullptr)
        {
            return 0;
        }
        return BinTreeNodes(tmp->left()) + BinTreeNodes(tmp->right()) + 1;
    }
    int BinTreeDepth(BinNode<E> *tmp) //获得二叉树的高度
    {
        if (tmp == nullptr)
        {
            return 0;
        }
        queue<pair<BinNode<E> *, int>> heightQueue;
        heightQueue.push(pair<BinNode<E> *, int>(tmp, 0));
        int maxHeight = -1;
        pair<BinNode<E> *, int> curr;
        while (!heightQueue.empty())
        {
            curr = heightQueue.front();
            heightQueue.pop();
            if (curr.second > maxHeight)
            {
                maxHeight = curr.second;
            }
            if (curr.first->left() != nullptr)
            {
                heightQueue.push(pair<BinNode<E> *, int>(curr.first->left(), curr.second + 1));
            }
            if (curr.first->right() != nullptr)
            {
                heightQueue.push(pair<BinNode<E> *, int>(curr.first->right(), curr.second + 1));
            }
        }
        return maxHeight;
    }
    int BinTreeLeafs(BinNode<E> *tmp) //获得二叉树的叶子结点数
    {
        if (tmp == nullptr)
        {
            return 0;
        }
        if (tmp->left() == nullptr && tmp->right() == nullptr)
        {
            return 1;
        }
        return BinTreeLeafs(tmp->left()) + BinTreeLeafs(tmp->right());
    }
    bool find(BinNode<E> *tmp, E e) //查找二叉树中是否含有某个名为e的结点
    {
        if (tmp == nullptr)
        {
            return false;
        }
        if (tmp->getValue() == e)
        {
            return true;
        }
        return find(tmp->left(), e) + find(tmp->right(), e);
    }

public:
    BinTree() //默认构造函数
    {
        root = new BinNode<E>;
    }
    ~BinTree() //析构函数
    {
        clear(root);
    }
    bool BinTreeEmpty() //判断二叉树是否为空
    {
        if (root == NULL)
            return true;
        else
            return false;
    }
    BinNode<E> *getRoot() //获得根节点
    {
        return root;
    }
    void setRoot(BinNode<E> *r) //设置根节点
    {
        root = r;
    }
    //下面的函数是对外的函数，所以内部还会有一些同名的函数，但是参数列表不一样，实现数据的封装，外部的调用不会涉及到内部的数据对象
    void clear() //清空二叉树
    {
        clear(root);
        root = NULL;
    }
    void preOrder(void (*visit)(BinNode<E> *node)) //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        preOrder(root, visit);
    }
    void inOrder(void (*visit)(BinNode<E> *node)) //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        inOrder(root, visit);
    }
    void postOrder(void (*visit)(BinNode<E> *node)) //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        postOrder(root, visit);
    }
    void LevelOrderTranverse(void (*visit)(BinNode<E> *node)) //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        LevelOrderTranverse(root, visit);
    }
    int BinTreeDepth() //获得二叉树深度
    {
        return BinTreeDepth(root);
    }
    int BinTreeNodes() //获得二叉树结点数
    {
        return BinTreeNodes(root);
    }
    int BinTreeHeight() //获得二叉树高度
    {
        return BinTreeHeight(root);
    }
    int BinTreeLeafs() //获得二叉树叶子结点数
    {
        return BinTreeLeafs(root);
    }
    bool find(E e) //查找二叉树中是否存在名为e的结点
    {
        return find(root, e);
    }
};

template <typename E>
void printNode(BinNode<E> *tmp) //打印结点的值的函数
{
    cout << tmp->getValue() << "  ";
}

template <typename E>
BinNode<E> *creatBinaryTree(string s[], int &x, int n) //构建二叉树的主函数，根据先序遍历，采用递归思想构建
{
    if (s[x] == "/")
        return NULL;
    else
    {
        BinNode<E> *node = new BinNode<E>(s[x]);
        x = x + 1;
        if (x < n)
            ;
        node->setLeft(creatBinaryTree<E>(s, x, n));
        x = x + 1;
        if (x < n)
            ;
        node->setRight(creatBinaryTree<E>(s, x, n));
        return node;
    }
}

void creatBinaryTree(BinTree<string> *BT) //构建二叉树的函数，包含了上面的构建二叉树的主函数，仅仅起到了在主函数中简洁一些的作用
{
    //cout  <<  "现在进入构建二叉树程序......"  <<  endl;
    //cout  <<  "请输入二叉树有多少个结点(空结点也计算其中)"  <<  endl;
    int n = 0;
    cin >> n;
    //cout  <<  "请按preorder顺序输入，遇到NULL请输入'/',用空格隔开或者回车隔开均可以"  <<  endl;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int now = 0;
    BT->setRoot(creatBinaryTree<string>(s, now, n));
}

int main()
{
    //本程序的二叉树是一个模板类，若想改变为别的类型，可以在相关的地方在“<>”中修改相关参数,本程序默认为最具有普遍性的string
    BinTree<string> *BT = new BinTree<string>;
    creatBinaryTree(BT);
    string strfind;
    cin >> strfind;
    //在这里，已经构建好了一棵二叉树
    //下面是二叉树的基本函数操作的展示

    cout << "0:判断是否为空树：";
    if (BT->BinTreeEmpty() == true)
        cout << "是" << endl;
    else
        cout << "否" << endl;
    cout << "1:前序遍历:";
    BT->preOrder(printNode);
    cout << endl;
    cout << "2:中序遍历:";
    BT->inOrder(printNode);
    cout << endl;
    cout << "3:后序遍历:";
    BT->postOrder(printNode);
    cout << endl;
    cout << "4:层次遍历:";
    BT->LevelOrderTranverse(printNode);
    cout << endl;
    cout << "5:记录树的深度:";
    cout << BT->BinTreeDepth() << endl;
    cout << "6:记录树的高度:";
    cout << BT->BinTreeHeight() << endl;
    cout << "7:统计结点:";
    cout << BT->BinTreeNodes() << endl;
    cout << "8:统计叶子结点:";
    cout << BT->BinTreeLeafs() << endl;
    cout << "9:查找" << strfind << ":";
    if (BT->find(strfind) == true)
        cout << "存在" << endl;
    else
        cout << "不存在" << endl;
    cout << "10:是否清空:";
    BT->clear();
    cout << "已清空" << endl;
    cout << "5:记录树的深度:";
    cout << BT->BinTreeDepth() << endl;
    cout << "6:记录树的高度:";
    cout << BT->BinTreeHeight() << endl;
    cout << "7:统计结点:";
    cout << BT->BinTreeNodes() << endl;
    cout << "8:统计叶子结点:";
    cout << BT->BinTreeLeafs() << endl;
    return 0;
}