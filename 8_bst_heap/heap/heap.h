#ifndef _HEAP_
#define _HEAP_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct BinTreeNodeType
{
	int data;
    int visit;
}BinTreeNode;

typedef struct BinTreeType
{
    int rear;
    int max_elem_cnt;
	struct BinTreeNodeType* pElement;
}BinTree;

#define TRUE		1
#define FALSE		0

#endif