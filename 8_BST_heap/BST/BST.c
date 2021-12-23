#include "binsearchtree.h"

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

BinSearchTreeNode* RLlast(BinSearchTreeNode *node)
{
    BinSearchTreeNode *curr;

    curr = node->pRightChild;
    while(curr->pLeftChild)
    {
        curr = curr->pLeftChild;
    }
    return (curr);
}

BinSearchTree* createBinSearchTree()
{
    BinSearchTree *tree;

    tree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    tree->pRootNode = NULL;
    return (tree);
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
        printf("key is already have\n");
        return (FALSE);
    }
    link_PC_BST(parent, new_node);
    return (TRUE);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
    BinSearchTreeNode *remove, *replace;
    BinSearchTreeNode *parent, *child;

    remove = searchBST(pBinSearchTree, key);
    if(remove->key != key)
    {
        printf("key isn't exist\n");
        return (FALSE);
    }
    //no child
    if(!remove->pLeftChild && !remove->pRightChild)
    {
        free(remove);
        remove = NULL;
    }
    //two child
    else if(remove->pLeftChild && remove->pRightChild)
    {
        replace = RLlast(remove);
        parent = replace->pParent;
        if(replace->pRightChild)
            link_PC_BST(parent, replace->pRightChild);
        else
            parent->pLeftChild = NULL;
        replace->pLeftChild = remove->pLeftChild;
        replace->pRightChild = remove->pRightChild;
        if(remove != pBinSearchTree->pRootNode)
            link_PC_BST(remove->pParent, replace);
        else
            pBinSearchTree->pRootNode = replace;
        free(remove);
        remove = NULL;
    }
    //one child
    else
    {
        parent = remove->pParent;
        if(remove->pLeftChild)
            child = remove->pLeftChild;
        else
            child = remove->pRightChild;
        link_PC_BST(parent, child);
        free(remove);
        remove = NULL;
    }
    return(TRUE);
}

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

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
    BinSearchTreeNode *rootNode;
    
    if(!pBinSearchTree)
        return ;
    rootNode = pBinSearchTree->pRootNode;
    if(!rootNode)
        return ;
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

QueueList* creatQueue()
{
    QueueList* Queue;

    Queue = (QueueList *)malloc(sizeof(QueueList));
    Queue->head = NULL;
    Queue->rear = NULL;
    return (Queue);
}

void deleteQueue(QueueList *Queue)
{
    QNode *Curr;
    QNode *Next;

    Curr = Queue->head;
    while(Curr)
    {
        Next = Curr->next;
        free(Curr);
        Curr = Next;
    }
    free(Queue);
}

void enque(QueueList *Queue, BinSearchTreeNode *data)
{
    QNode *new_node;
    if(!Queue)
        return;
    new_node = (QNode *)malloc(sizeof(QNode));
    new_node->data = data;
    new_node->next = NULL;
    if(!Queue->rear)
    {
        Queue->head = new_node;
        Queue->rear = new_node;
    }
    else
    {
        Queue->rear->next = new_node;
        Queue->rear = new_node;
    }
}

void levelOrderTraversalBinTree(BinSearchTreeNode* pNode)
{
    QueueList *Queue;
    QNode *curr;

    Queue = creatQueue();
    enque(Queue, pNode);
    curr = Queue->head;
    while(curr)
    {
        printf("[%d : %c] ", curr->data->key, curr->data->value);
        if(curr->data->pLeftChild)
            enque(Queue, curr->data->pLeftChild);
        if(curr->data->pRightChild)
            enque(Queue, curr->data->pRightChild);
        curr = curr->next;
    }
    printf("\n");
    deleteQueue(Queue);
}

int main(void)
{
    int number, key;

    BinSearchTree *tree;
    BinSearchTreeNode node = {0, 0, 0, 0, 0};
    tree = createBinSearchTree();

    while (1)
    {
        printf("1 : Insert 2 : Remove 3 : Display 4 : DeleteAll\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("key : ");
            scanf(" %d", &node.key);
            printf("value : ");
            scanf(" %c", &node.value);
            insertElementBST(tree, node);
            break;
        case 2:
            printf("Remove key : ");
            scanf(" %d", &key);
            deleteElementBST(tree, key);
            break;
        case 3:
            levelOrderTraversalBinTree(tree->pRootNode);
            break;
        case 4:
            deleteBinSearchTree(tree);
            return 0;
        default:
            break;
        }
    }
}