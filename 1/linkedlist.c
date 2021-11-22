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


LinkedList* createLinkedList() //node한개생성인지 노드2개리스트1개인지..!
{
	ListNode	*node;

	node = malloc(sizeof(LinkedList));
	node->data = NULL;
	node->pLink = NULL;
	return (node);
}
//data, nextlink 모두 NULL인 노드 하나

int addLLElement(LinkedList* pList, int position, ListNode element);
{
	while(position--)
		pList->headerNode->data = pList->headerNode->pLink;
	temp->data = pList->headerNode->data;
	pList->headerNode->data = element->data;
	element->pLink = temp->data;
	pList->currentElementCount += 1;
}

int removeLLElement(LinkedList* pList, int position)
{
	while(position--)
		pList->headerNode->data = pList->headerNode->pLink;
//	free
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	while(position--)
		pList->headerNode->data = pList->headerNode->pLink;
	return (pList->headerNode);

}

void clearLinkedList(LinkedList* pList)
{
	while(pList->headerNode->data)
	{
		pList->headerNode->data = NULL;
		pList->headerNode->data = pList->headerNode->pLink;
		free
	}
}

int getLinkedListLength(LinkedList* pList)
{
	int length = 0;

	while(pList)
	{
		pList->headerNode = pList->headerNode->pLink;
		length++;
	}
	return (length);
}

void deleteLinkedList(LinkedList* pList);
