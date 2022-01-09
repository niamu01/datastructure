#include "binsearchtree.h"

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
    if(!pTreeNode)
        return (FALSE);
    if(pTreeNode->key == key)
        return pTreeNode;
    if(pTreeNode->key < key)
        return (searchInternalRecursiveBST(pTreeNode->pRightChild, key));
    else
        return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key));
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
    if(!pBinSearchTree)
        return (FALSE);
    BinSearchTreeNode *curr = pBinSearchTree->pRootNode;
    if(!curr)
        return (FALSE);
    while(1)
    {
        if(curr->key == key)
            return (curr);
        if(curr->key < key)
        {
            if(curr->pRightChild)
                curr = curr->pRightChild;
            else
                return (curr);
        }
        if(curr->key > key)
        {
            if(curr->pLeftChild)
                curr = curr->pLeftChild;
            else
                return (curr);
        }
    }
    return (FALSE);
}