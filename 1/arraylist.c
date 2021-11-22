#include "arraylist.h"

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
	int i = 0;
	ArrayList *array;

	while(maxElementCount--)
	{
		array.pElement[i++].data = NULL;
	}
	return (array);
}

void deleteArrayList(ArrayList* pList)
{
	int i = 0;
	while(pList)
	{
		pList[i++] = NULL;
	}
}

int isArrayListFull(ArrayList* pList);

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int i = 0;
	int length;

	length = getArrayListLength(pList) - 1;
	while (pList[position])
	{
		pList[length + 1 - i] = pList[length - i];
		i++;
	}
	pList[position] = element;
	return (0); // 무엇을 반환하는지>??
}

int removeALElement(ArrayList* pList, int position)
{
	int i = 0;

	pList[position] = NULL;
	while(pList[position + i])
	{
		pList[position + i] = pList[position + i + 1];
		i++;
	}
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	return (pList[position]);
}

void displayArrayList(ArrayList* pList); //아예 지우고 이걸로 바꾸는건지 position이 왜 없지

void clearArrayList(ArrayList* pList)
{
	pList[i++] = NULL; ... //delete와 clear의 차이
}

int getArrayListLength(ArrayList* pList)
{
	int length = 0;

	while(pList)
	{
		pList[length++];
	}
	return (length);
}
