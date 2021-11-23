#include "arraylist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc
#include <stdio.h> //printf

//

ArrayList* createArrayList(int maxElementCount)
{	
	ArrayList *array;

	if (maxElementCount < 0)
		return (NULL);
	if (!(array = (ArrayList *)malloc(sizeof(ArrayList))))
		return (NULL);
	//array로 선언을하고 malloc없이 &array반환하는것은 불가능한지! 
	//-> 그렇게하면 함수가 끝나면 value값이 날라가지 않나요?
	array->currentElementCount = 0;
	array->maxElementCount = maxElementCount; 
	if (!(array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * array->maxElementCount)))
		return (NULL);
	//pElement에 0으로 채워져야하나요?
	//-> 네 쓰레기값보단 0으로 처리하는게 좋다 생각합니다
	//-> 0을 넣으려면 구분이 안되지 않나요? 그리고 current변수가 있기도 하고 초기화는 안해도 된다 생각합니다
	//->변수가 들어있는지 아닌지 구분하는 함수 (할당시++ 삭제시--)

	return (array);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return (NULL);
	//mki: clearArrayList
	free(pList->pElement);
	free(pList);
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

	if(!pList || &element == NULL)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	//mki: pList->max <= pList->current
	if (isArrayListFull(pList))
		return (FALSE);
	//yongckim: JAVA에서는 새롭게 할당해서 끼워넣어주는데 구현할땐 예외처리를 하라 하셨음
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
	int i = position;
	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	while(i < pList->currentElementCount - 1)
	{
		pList->pElement[i] = pList->pElement[i + 1];
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
	printf("MAX ELEMENT COUNT:%d\n", pList->maxElementCount);
	printf("CURRENT ELEMENT COUNT:%d\n", pList->currentElementCount);
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pElement[%d]: %d\n", i, pList->pElement[i].data);
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
