#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
    BinSearchTree *tree;

    tree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    tree->pRootNode = NULL;
    return (tree);
}

BinSearchTreeNode *createNode(BinSearchTreeNode element)
{
    BinSearchTreeNode *node;

    node = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
    *node = element;
    return (node);
}

void    link_PC_BST(BinSearchTreeNode *parent, BinSearchTreeNode *child)
{
    if(parent->key > child->key)
    {
        parent->pLeftChild = child;
        child->pParent = parent;
    }
    else
    {
        parent->pRightChild = child;
        child->pParent = parent;
    }
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
    BinSearchTreeNode *new_node;
    BinSearchTreeNode *parent;

    new_node = createNode(element);
    if(!pBinSearchTree->pRootNode)
    {
        pBinSearchTree->pRootNode = new_node;
        return (TRUE);
    }
    parent = searchBST(pBinSearchTree, new_node->key);
    if(parent->key == new_node->key)
    {
        printf("key is already exist\n");
        return (FALSE);
    }
    link_PC_BST(parent, new_node);
    return (TRUE);
}