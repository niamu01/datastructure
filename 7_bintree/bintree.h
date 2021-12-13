#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdlib.h>
#include <stdio.h>

typedef struct BinTreeNodeType
{
	char data;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

typedef struct QueueNode
{
    BinTreeNode *data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode *head;
    QNode *rear;
}QueueList;

BinTree* makeBinTree(BinTreeNode *rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);
void preorderTraversalBinTree(BinTreeNode* pNode);
void inorderTraversalBinTree(BinTreeNode* pNode);
void levelOrderTraversalBinTree(BinTreeNode* pNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0
#endif