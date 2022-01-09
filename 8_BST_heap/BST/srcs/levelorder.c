#include "binsearchtree.h"

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

    if(!pNode)
        return ;
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