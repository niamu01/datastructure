#include "linkedstack.h"

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *pop;

	if (isLinkedStackEmpty(pStack))
		return (FALSE);
	pop = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	//다른조는 pStack->pTop = pop->pLink이라 함
	pStack->currentElementCount--;
	return (pop);
}
