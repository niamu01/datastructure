#include "binsearchtree.h"

static BinSearchTreeNode *RLlast(BinSearchTreeNode *node)
{
    BinSearchTreeNode *curr;

    curr = node->pRightChild;
    while (curr->pLeftChild)
        curr = curr->pLeftChild;
    return (curr);
}

static void delete_Two_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *replace;
    BinSearchTreeNode *parent;

    replace = RLlast(remove);
    parent = replace->pParent; //대체할 노드의 부모.
    if (parent != remove) //제거할 노드 != 대체할 노드의 부모
    {
    //====대체할 노드의 부모와 대체할 노드의 자식을 연결=========
        if (replace->pRightChild)
            link_PC_BST(parent, replace->pRightChild);
        else
            parent->pLeftChild = NULL;
    //====대체할 노드의 부모 - 대체할 노드의 자식연결 종료=======
        replace->pLeftChild = remove->pLeftChild;
        replace->pRightChild = remove->pRightChild; //제거할 노드가 대체할 노드의 부모일경우, right_child가 자신을 가리키게됨
    }
    else//무한루프 방지
    {
        replace->pLeftChild = remove->pLeftChild;
        replace->pRightChild = NULL;
    }
    if (remove != pBinSearchTree->pRootNode)
        link_PC_BST(remove->pParent, replace);
    else
        pBinSearchTree->pRootNode = replace;
    free(remove);
    remove = NULL;
}

static void delete_One_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *parent;
    BinSearchTreeNode *child;

    if (remove->pLeftChild)
        child = remove->pLeftChild;
    else
        child = remove->pRightChild;
    if (remove != pBinSearchTree->pRootNode)
    {
        parent = remove->pParent;
        link_PC_BST(parent, child);
    }
    else
        pBinSearchTree->pRootNode = child;

    free(remove);
    remove = NULL;
}

static void delete_NO_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *parent;

    if (remove == pBinSearchTree->pRootNode)
        pBinSearchTree->pRootNode = NULL;
    else
    {
        parent = remove->pParent;
        if (parent->pLeftChild == remove)
            parent->pLeftChild = NULL;
        else
            parent->pRightChild = NULL;
    }
    free(remove);
    remove = NULL;
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *remove;

    if (!pBinSearchTree || !pBinSearchTree->pRootNode)
    {
        printf("Tree is empty\n");
        return (FALSE);
    }
    remove = searchBST(pBinSearchTree, key);
    if (remove->key != key)
    {
        printf("key isn't exist\n");
        return (FALSE);
    }
    //no child
    if (!remove->pLeftChild && !remove->pRightChild)
        delete_NO_child(pBinSearchTree, remove);
    //two child
    else if (remove->pLeftChild && remove->pRightChild)
        delete_Two_child(pBinSearchTree, remove);
    //one child
    else
        delete_One_child(pBinSearchTree, remove);
    return (TRUE);
}