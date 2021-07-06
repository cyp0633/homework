//二叉树遍历，从前序、中序到后序 Ref:https://blog.csdn.net/weixin_51307568/article/details/118437375
#include <cstdio>
#include <iostream>
using namespace std;
void postOrder(string preOrder, string inOrder);
int main()
{
    string preOrder, inOrder;
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        cin >> preOrder >> inOrder;
        postOrder(preOrder, inOrder);
        putchar('\n');
    }
    return 0;
}
void postOrder(string preOrder, string inOrder)
{
    if (preOrder.empty()) //自然的会想length=0，但empty效果一样，而且更快
    {
        return;
    }
    char root = preOrder[0];                                              //该子树的根节点
    int rootPos = inOrder.find(root);                                     //其实这个rootPos也是左子树的长度
    postOrder(preOrder.substr(1, rootPos), inOrder.substr(0, rootPos));   //左子树。不用再傻乎乎找先序的左右子树分界线了啊！长度是一样的啊！
    postOrder(preOrder.substr(rootPos + 1), inOrder.substr(rootPos + 1)); //右子树。第二个参数为空，就是一直截到末尾
    putchar(root);
    return;
}