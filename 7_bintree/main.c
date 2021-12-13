#include "bintree.h"

int main(void)
{
    BinTree *tree;
    BinTreeNode A = {'A', NULL, NULL};
    BinTreeNode B = {'B', NULL, NULL};
    BinTreeNode C = {'C', NULL, NULL};
    BinTreeNode D = {'D', NULL, NULL};
    BinTreeNode E = {'E', NULL, NULL};
    BinTreeNode F = {'F', NULL, NULL};
    BinTreeNode G = {'G', NULL, NULL};
    BinTreeNode H = {'H', NULL, NULL};
    BinTreeNode I = {'I', NULL, NULL};
    BinTreeNode J = {'J', NULL, NULL};
    BinTreeNode K = {'K', NULL, NULL};
    BinTreeNode L = {'L', NULL, NULL};
    BinTreeNode M = {'M', NULL, NULL};

    insertLeftChildNodeBT(&D, &H);
    insertRightChildNodeBT(&D, &I);
    insertLeftChildNodeBT(&E, &J);
    insertRightChildNodeBT(&F, &K);
    insertLeftChildNodeBT(&G, &L);
    insertRightChildNodeBT(&G, &M);
    insertLeftChildNodeBT(&B, &D);
    insertRightChildNodeBT(&B, &E);
    insertRightChildNodeBT(&C, &G);
    insertLeftChildNodeBT(&C, &F);
    insertLeftChildNodeBT(&A, &B);
    insertRightChildNodeBT(&A, &C);
    tree = makeBinTree(&A);
    BinTreeNode *node;

    node = getRootNodeBT(tree);
    printf("RootNode: %c\n", node->data);
    levelOrderTraversalBinTree(node);
    deleteBinTreeNode(node);
}