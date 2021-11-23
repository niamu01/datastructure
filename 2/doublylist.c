#include "doublylist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 저장된 원소의 개수
	DoublyListNode	headerNode;		// 헤더 노드(Header Node)
} DoublyList;

/*------------------------------------코드-부분------------------------------------*/

DoublyList* createDoublyList() //이중연결리스트
{
	DoublyList	*Dlist;

	if (!(Dlist = (DoublyList *)malloc(sizeof(DoublyList))))
		return (NULL);
	Dlist->headerNode.data = NULL;
	Dlist->headerNode.pLLink = NULL;
	Dlist->headerNode.pRLink = NULL;
	Dlist->currentElementCount = 0;
	return (Dlist);
//모든 요소를 초기화(?) & 구조체 malloc
//1강 linkedlist 그대로 들고옴
}

void deleteDoublyList(DoublyList* pList) //이중연결리스트 지우기
{
	if(!pList)
		return (NULL);
	clearDoublyList(pList);
	free(pList);
//1강 linkedlist 그대로 들고옴
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element); //이중연결리스트에 인자 추가

int removeDLElement(DoublyList* pList, int position) //이중연결리스트에 인자 삭제
{
	DoublyListNode	*prev;
	DoublyListNode	*delnode;

	if(!pList)
		return (NULL);
	if(position < 0 || po)
}

void clearDoublyList(DoublyList* pList); //이중연결리스트 비우기

int getDoublyListLength(DoublyList* pList); //이중연결리스트 길이 재기

DoublyListNode* getDLElement(DoublyList* pList, int position); //이중연결리스트 인자값

void displayDoublyList(DoublyList* pList); //이중연결리스트 요소 출력