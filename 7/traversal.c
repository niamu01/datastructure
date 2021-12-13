#include "bintree.h"

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

void enque(QueueList *Queue, BinTreeNode *data)
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

void preorderTraversalBinTree(BinTreeNode* pNode)
{
    if (!pNode)
        return ;
    printf("%c", pNode->data);
    if (pNode->pLeftChild)
        preorderTraversalBinTree(pNode->pLeftChild);
    if (pNode->pRightChild)
        preorderTraversalBinTree(pNode->pRightChild);
    return ;
}

void inorderTraversalBinTree(BinTreeNode* pNode)
{
    if (!pNode)
        return ;
    if (pNode->pLeftChild)
        inorderTraversalBinTree(pNode->pLeftChild);
    printf("%c", pNode->data);
    if (pNode->pRightChild)
        inorderTraversalBinTree(pNode->pRightChild);
    return ;
}

void levelOrderTraversalBinTree(BinTreeNode* pNode)
{
    QueueList *Queue;
    QNode *curr;

    Queue = creatQueue();
    enque(Queue, pNode);
    curr = Queue->head;
    while(curr)
    {
        printf("%c", curr->data->data);
        if(curr->data->pLeftChild)
            enque(Queue, curr->data->pLeftChild);
        if(curr->data->pRightChild)
            enque(Queue, curr->data->pRightChild);
        curr = curr->next;
    }
    deleteQueue(Queue);
}