#include "binsearchtree.h"

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
    BinSearchTreeNode *rootNode;
    
    if(!pBinSearchTree)
        return ;
    rootNode = pBinSearchTree->pRootNode;
    if(!rootNode)
    {
        free(pBinSearchTree);
        return ;
    }
    deleteBinSearchTreeInternal(rootNode);
    free(pBinSearchTree);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
    if(pTreeNode->pLeftChild)
        deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
    if(pTreeNode->pRightChild)
        deleteBinSearchTreeInternal(pTreeNode->pRightChild);
    free(pTreeNode);
    pTreeNode = NULL;
}