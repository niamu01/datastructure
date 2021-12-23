#include "linkedqueue.h"

LinkedQueue* createLinkedQueue()
{
	LinkedQueue *LD;

	if (!(LD = (LinkedQueue *)calloc(1, sizeof(LinkedQueue))))
	{
		printf("[error] malloc failure : LD\n");
		return (FALSE);
	}
	return (LD);
}

int isLinkedQueueFull(LinkedQueue* pDeque)
{
	if (pDeque == NULL)
		return (FALSE);
	return (FALSE);
} // 링크드리스트 구조에, maxElementCount가 없으므로 배열이 가득 찰 수 없음. 무한히 확장될 수 있다.

int isLinkedQueueEmpty(LinkedQueue* pDeque) //비어있으면 1반환
{
	if (pDeque == NULL)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int insertFrontLD(LinkedQueue* pDeque, QueueNode element)
{
	QueueNode *newNode;
		
	newNode = (QueueNode *)calloc(1, sizeof(QueueNode));
	if (newNode == NULL)
		return (FALSE);
	newNode->data = element.data;
	newNode->pRLink = NULL;
	newNode->pLLink = NULL;
	if (isLinkedQueueEmpty(pDeque)) //비어있었으면 자신을 가리킴
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		pDeque->pFrontNode->pLLink = newNode;
		newNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedQueue* pDeque, QueueNode element)
{
	QueueNode *newNode;
		
	newNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (newNode == NULL)
		return (FALSE);
	newNode->data = element.data;
	newNode->pRLink = NULL;
	newNode->pLLink = NULL;
	if (isLinkedQueueEmpty(pDeque))
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		pDeque->pRearNode->pRLink = newNode;
		newNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

QueueNode* deleteFrontLD(LinkedQueue* pDeque)
{
	QueueNode	*delNode = NULL;

	if (pDeque == NULL)
		return (FALSE);
	if (isLinkedQueueEmpty(pDeque)) //비어있는 덱에서는 지울수 없음
		return (FALSE);
	delNode = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	delNode->pRLink = NULL;
	//delNode->pLLink = NULL;
	pDeque->currentElementCount--;
	if (isLinkedQueueEmpty(pDeque) == TRUE)
		pDeque->pRearNode = NULL;
		//pDeque->pFrontNode = NULL;
	else // 노드가 2개 이상인 덱 (일반적인 경우)
		pDeque->pFrontNode->pLLink = NULL;  
	return (delNode);
}

QueueNode* deleteRearLD(LinkedQueue* pDeque)
{
	QueueNode	*delNode = NULL;

	if (pDeque == NULL)
		return (FALSE);
	if (isLinkedQueueEmpty(pDeque))
		return (FALSE);
	delNode = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	delNode->pLLink = NULL;
	//delNode->pRLink = NULL;
	pDeque->currentElementCount--; //위로올림
	if (isLinkedQueueEmpty(pDeque) == TRUE)
		pDeque->pFrontNode = NULL;
	else
		pDeque->pRearNode->pRLink = NULL;
	return (delNode);
}

QueueNode* peekFrontLD(LinkedQueue* pDeque)
{
	QueueNode *retNode = NULL;

	if (pDeque == NULL)
		return (FALSE);
	if (isLinkedQueueEmpty(pDeque))
		return (FALSE);
		retNode = pDeque->pFrontNode;
	return (retNode);
}

QueueNode* peekRearLD(LinkedQueue* pDeque)
{
	QueueNode *retNode = NULL;

	if (pDeque == NULL)
		return (FALSE);
	if (isLinkedQueueEmpty(pDeque))
		return (FALSE);
	retNode = pDeque->pRearNode;
	return (retNode);
}

void deleteLinkedQueue(LinkedQueue* pDeque)
{
    QueueNode *node = NULL;
    QueueNode *delnode = NULL;

	if (pDeque == NULL)
		return ;
    node = pDeque->pFrontNode;
    while (node)
    {
        delnode = node;
        node = node->pRLink;
        free(delnode);
    }
	free(pDeque);
}
