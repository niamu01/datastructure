#include "bintree.h"
//트리 만들기
BinTree* makeBinTree(BinTreeNode *rootNode)
{
    BinTree *tree;
    
    tree = (BinTree *)malloc(sizeof(BinTree));
    if (!tree)
        return NULL;
    tree->pRootNode = rootNode;
    return (tree);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
    if (!pParentNode)
        return (FALSE);
    pParentNode->pLeftChild = element;
    return (element);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
    if (!pParentNode)
        return (FALSE);
    pParentNode->pRightChild = element;
    return (element);
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
    free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    if(pNode->pLeftChild)
        deleteBinTreeNode(pNode->pLeftChild);
    if(pNode->pRightChild)
        deleteBinTreeNode(pNode->pRightChild);
    free(pNode);
    pNode = NULL;
}