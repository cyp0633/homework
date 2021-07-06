//二叉树遍历，从前序、中序到后序
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
string preorder, inorder;
void build(int preL, int preR, int inL, int inR); //其实这里也可以用substr函数，但有点麻烦
int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        cin >> preorder >> inorder;
        build(0, n - 1, 0, n - 1);
        putchar('\n');
    }
    return 0;
}
void build(int preL, int preR, int inL, int inR)
{
    if (preR - preL != inR - inL) //两种遍历长度不一样？万一呢？
    {
        //printf("Error Detected: Different Length\n");
    }
    if (preL > preR)
    {
        return;
    }
    char root = preorder[preL]; //得到root结点
    int inRootPos, preLeftEnd;
    for (inRootPos = inL; inRootPos <= inR; inRootPos++) //确定中序遍历中的root位置
    {
        if (inorder[inRootPos] == root)
        {
            break;
        }
    }
    if (inRootPos != inL) //有左子树
    {
        // for (preLeftEnd = preL + 1; preLeftEnd <= preR; preLeftEnd++) //确定先序遍历的左子树结束位置，这里要改改改
        // {
        //     if (preorder[preLeftEnd] == inorder[inRootPos - 1])
        //     {
        //         break;
        //     }
        // }
        if (inRootPos != inR) //有右子树，可以放心大胆往右取
        {
            for (preLeftEnd = preL + 1; preLeftEnd <= preR; preLeftEnd++) //逐个遍历左右子树中的结点
            {
                bool found = false;
                for (int i = inL; i < inRootPos - 1; i++) //左子树中是否有这个结点
                {
                    if (preorder[preLeftEnd] == inorder[i])
                    {
                        found = true;
                        break;
                    }
                }
                if (found == false) //没有？那左子树的末端就是它的上一个结点
                {
                    //preLeftEnd--;
                    break;
                }
            }
            build(preL + 1, preLeftEnd, inL, inRootPos - 1); //对左子树进行分治
        }
        else //没有右子树
        {
            preLeftEnd = preR;
            build(preL + 1, preR, inL, inRootPos - 1);
        }
    }
    else
    {
        preLeftEnd = preL; //没有左子树
    }
    build(preLeftEnd + 1, preR, inRootPos + 1, inR);
    putchar(root);
    return;
}