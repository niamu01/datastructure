#include "poly.h"

LinkedList* createLinkedList()
{
	LinkedList	*list;

	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return (NULL);
	list->headerNode.coef = 0;
	list->headerNode.degree = 0;
	list->headerNode.pLink = 0;
	list->currentElementCount = 0;
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;
	ListNode *newE;

	if(!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (!(newE = (ListNode *)malloc(sizeof(ListNode))))
		return (FALSE);
	newE->coef = element.coef;
	newE->degree = element.degree;
	newE->pLink = NULL;
	prev = &(pList->headerNode);
	while(position--)
		prev = prev->pLink;
	newE->pLink = prev->pLink;
	prev->pLink = newE;
	pList->currentElementCount++;
	return (TRUE);
}

int getLinkedListLength(LinkedList* pList)
{
	if(!pList)
		return (FALSE);
	return (pList->currentElementCount);
}