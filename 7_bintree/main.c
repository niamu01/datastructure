#include "bintree.h"

BinTreeNode* make_node(char data)
{
    BinTreeNode *dummy;
    dummy = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    dummy->data = data;
    dummy->pLeftChild = NULL;
    dummy->pRightChild = NULL;

    return(dummy);
}

BinTree* init(void)
{
    BinTreeNode *A = make_node('A');
    BinTreeNode *B = make_node('B');
    BinTreeNode *C = make_node('C');
    BinTreeNode *D = make_node('D');
    BinTreeNode *E = make_node('E');
    BinTreeNode *F = make_node('F');
    BinTreeNode *G = make_node('G');
    BinTreeNode *H = make_node('H');
    BinTreeNode *I = make_node('I');
    BinTreeNode *J = make_node('J');
    BinTreeNode *K = make_node('K');
    BinTreeNode *L = make_node('L');
    BinTreeNode *M = make_node('M');
    BinTree* tree = makeBinTree(A);

    insertLeftChildNodeBT(D, H);
    insertRightChildNodeBT(D, I);
    insertLeftChildNodeBT(E, J);
    insertRightChildNodeBT(F, K);
    insertLeftChildNodeBT(G, L);
    insertRightChildNodeBT(G, M);
    insertLeftChildNodeBT(B, D);
    insertRightChildNodeBT(B, E);
    insertRightChildNodeBT(C, G);
    insertLeftChildNodeBT(C, F);
    insertLeftChildNodeBT(A, B);
    insertRightChildNodeBT(A, C);

    return(tree);
}

void dummy(void)
{
    BinTree* tree = init();
    BinTreeNode *root;

    root = getRootNodeBT(tree);
    
    printf("PreOrder: ");
    preorderTraversalBinTree(root);
    printf("\nInOrder: ");
    inorderTraversalBinTree(root);
    printf("\nLevelOrder: ");
    levelOrderTraversalBinTree(root);
    printf("\n");
    deleteBinTree(tree);
}

int main(void)
{
    dummy();
    system("Leaks a");
}