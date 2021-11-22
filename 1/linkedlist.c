#include "linkedlist.h"
#include <stddef.h> //NULL == 0

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;


LinkedList* createLinkedList()
{
	LinkedList	*list;

	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return (NULL);
	list->headerNode.data = NULL;
	list->headerNode.pLink = NULL;
	list->currentElementCount = 0;
	
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *temp;

	if(!pList || &element == NULL) //&element?
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	temp = &pList->headerNode;
	while(position--)
		temp = temp->pLink;
	element.pLink = temp->pLink->pLink;
	temp->pLink = &element;
	pList->currentElementCount++;
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	ListNode *delnode;

	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	temp = &pList->headerNode;
	while(position--)
		temp = temp->pLink;
	delnode = temp->pLink;
	temp->pLink = temp->pLink->pLink;
	free(delnode);
	pList->currentElementCount--;
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *temp;

	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	temp = &pList->headerNode;
	position++;
	while(position--)
		temp = temp->pLink;
	return (temp);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *temp;

	if(!pList)
		return (NULL);
	while(pList->currentElementCount > 0)
		removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
	if(!pList)
		return (NULL);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if(!pList)
		return (NULL);
	clearLinkedList(pList);
	free(pList);
}