#include "arraylist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc
#include <stdio.h> //printf

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayListNode *pElement;	// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList* createArrayList(int maxElementCount)
{	
	ArrayList *array;

	if (maxElementCount < 0)
		return (NULL);
	if (!(array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount))) //pElement에만 말록하면 안되고 array전체에 malloc해야함
		return (NULL);
	array->currentElementCount = 0;
	array->maxElementCount = maxElementCount; 
	//pElement에도 값이 들어가 있어야함 (NULL)
	return (array);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return (NULL);
	free(pList->pElement);
	//pList도 free해야함!!
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (NULL);
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int i = pList->currentElementCount - 1;

	if(!pList || &element == NULL) //&element? //element대신 isArrayListFull로 검사
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	while (i > position)
	{
		pList->pElement[i] = pList->pElement[i - 1];
		i--;
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	int i = 0;
	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	while(i + position < pList->currentElementCount - 1)
	{
		pList->pElement[position + i] = pList->pElement[position + i + 1];
		i++;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (&(pList->pElement)[position]);
}

void displayArrayList(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	printf("최대 원소 개수:%d\n", pList->maxElementCount);
	printf("현재 원소 개수:%d\n", pList->currentElementCount);
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pElement[%d]: %d\n", i, pList->pElement[i].data);
	//empty의 경우?
}

void clearArrayList(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	for (int i = pList->currentElementCount - 1; i >= 0; i--)
		removeALElement(pList, i);
}

int getArrayListLength(ArrayList* pList)
{
	if(!pList)
		return (NULL);
	return (pList->currentElementCount);
}
