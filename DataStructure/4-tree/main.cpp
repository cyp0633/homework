#include "./tree.h"
#include <cstdio>
#include <iostream>
using namespace std;
bool compare(Node *aRoot, Node *bRoot)
{
    if ((aRoot == nullptr && bRoot != nullptr) || (aRoot != nullptr && bRoot == nullptr))
    {
        return false;
    }
    if (aRoot == nullptr && bRoot == nullptr)
    {
        return true;
    }
    if (aRoot->element() != bRoot->element())
    {
        return false;
    }
    return compare(aRoot->left(), bRoot->left()) && compare(aRoot->right(), bRoot->right());
}
int main()
{
    Tree a;
    getchar();
    Tree b;
    b.goRoot();
    char bRootVal = b.getValue();
    a.startSearch(bRootVal);
    bool isSubtree = compare(a.getCurrPtr(), b.getCurrPtr());
    if (isSubtree)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}