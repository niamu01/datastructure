#include "poly.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
	int ret = FALSE, i = 0;

	ListNode node;
	node.pLink = NULL;
	node.coef = coef;
	node.degree = degree;
	if (pList != NULL)
	{
		int length = getLinkedListLength(pList);
		ret = addLLElement(pList, length, node);
	}
	return ret;
}

void addPoly(LinkedList *A, LinkedList *B, LinkedList *C)
//둘 다 NULL인 경우
{
	ListNode *pA = A->headerNode.pLink;
	ListNode *pB = B->headerNode.pLink;

	int sum;
	while (pA && pB)
	{
		if (pA->degree == pB->degree)
		{
			sum = pA->coef + pB->coef;
			addPolyNodeLast(C, sum, pA->degree);
			pA = pA->pLink;
			pB = pB->pLink;
		}
		else if (pA->degree > pB->degree)
		{
			addPolyNodeLast(C, pA->coef, pA->degree);
			pA = pA->pLink;
		}
		else
		{
			addPolyNodeLast(C, pB->coef, pB->degree);
			pB = pB->pLink;
		}
	}
	for (; pA != NULL; pA = pA->pLink)
		addPolyNodeLast(C, pA->coef, pA->degree);
	for (; pB != NULL; pB = pB->pLink)
		addPolyNodeLast(C, pB->coef, pB->degree);
}

void print_list(ListNode *curr)
{
	while(curr)
	{
		printf("%d * x ^ %d\n", curr->coef, curr->degree);
		curr = curr->pLink;
	}
}

int main()
{
	LinkedList *A = createLinkedList();
	LinkedList *B = createLinkedList();
	LinkedList *C = createLinkedList();

//	addPolyNodeLast(A, 6, 6);
//	addPolyNodeLast(A, 4, 5);
//	addPolyNodeLast(A, 2, 2);
	addPolyNodeLast(A, 0, 0);
	
	addPolyNodeLast(B, 1, 5);
	addPolyNodeLast(B, 2, 4);
	addPolyNodeLast(B, 3, 2);
	addPolyNodeLast(B, 4, 0);
	
	addPoly(A, B, C);

	print_list(&A->headerNode);
	printf("\n");
	print_list(&B->headerNode);
	printf("\n");
	print_list(&C->headerNode);
	printf("\n");
	return 0;
}