#include "bintree.h"
//트리 만들기
BinTree* makeBinTree(BinTreeNode *rootNode)
{
    BinTree *tree;
    BinTreeNode *root_node;

    tree = (BinTree *)malloc(sizeof(BinTree));
    if (!tree)
        return NULL;
    root_node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if (!root_node)
        return NULL;
    root_node = rootNode;
//    *root_node = rootNode;

    tree->pRootNode = root_node;
    return (tree);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
    BinTreeNode *lnode;

    if (!pParentNode)
        return (FALSE);
    lnode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if (!lnode)
        return (FALSE);
    (lnode) = element;
    pParentNode->pLeftChild = lnode;
    return (lnode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
    BinTreeNode *rnode;

    if (!pParentNode)
        return (FALSE);
    rnode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if (!rnode)
        return (FALSE);
    (rnode) = element;
    pParentNode->pRightChild = rnode;
    return (rnode);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if(!pBinTree)
        return (FALSE);
    return(pBinTree->pRootNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if(!pNode || !pNode->pLeftChild)
        return (FALSE);
    return(pNode->pLeftChild);
}
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if(!pNode || !pNode->pRightChild)
        return (FALSE);
    return(pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
    BinTreeNode *rootNode;
    
    if(!pBinTree)
        return ;
    rootNode = getRootNodeBT(pBinTree);
    if(!rootNode)
        return ;
    deleteBinTreeNode(rootNode);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    if(pNode)
        return ;
    if(pNode->pLeftChild)
        deleteBinTreeNode(pNode->pLeftChild);
    if(pNode->pRightChild)
        deleteBinTreeNode(pNode->pRightChild);
    //
    free(pNode);
    pNode = NULL;
    //
}