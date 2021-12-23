#include "heap.h"

//display

void    display_heap(BinTree *tree)
{
    int max = tree->rear;
    for(int i  = 1 ; i < max ; i++)
        printf(" %d", tree->pElement[i].data);
    printf("\n");
}

//min max? -> min!
int     child_compare(BinTree *tree, int index1, int index2)
{
    //both not visited
    if(tree->pElement[index1].visit == 0)
        return (FALSE);
    //second child not visited
    if(tree->pElement[index2].visit == 0)
        return (index1);
    //compare
    if(tree->pElement[index1].data < tree->pElement[index2].data)
        return (index1);
    return (index2);
}

int     compare(int a, int b)
{
    if(a > b)
        return (TRUE);
    return(FALSE);
}

BinTree* createBintree(int n)
{
    BinTree *tree;

    tree = (BinTree *)malloc(sizeof(BinTree));
    tree->rear = 1;
    tree->max_elem_cnt = n;
    tree->pElement = (BinTreeNode *)malloc(sizeof(BinTreeNode) * (n + 1));

    return (tree);
}

void    Insert_BinTree(BinTree *tree, int data)
{
    int upper = tree->rear;
    int parent, tmp;

    if (tree->rear == tree->max_elem_cnt)
        return ;
    tree->pElement[tree->rear].data = data;
    tree->pElement[tree->rear].visit = 1;
    while (upper > 1)
    {
        parent = upper / 2;
        // swap with parent
        if(compare(tree->pElement[parent].data, tree->pElement[upper].data))
        {
            tmp = tree->pElement[parent].data;
            tree->pElement[parent].data = tree->pElement[upper].data;
            tree->pElement[upper].data = tmp;
        }
        else
            break ;
        //
        upper = parent;
    }
    tree->rear++;
}

void    Delete_BinTree(BinTree *tree)
{
    int down = 1;
    int child, tmp;

    if (tree->rear == 1)
        return ;
    tree->pElement[down].data = tree->pElement[--tree->rear].data;
    tree->pElement[tree->rear].visit = 0;
    while (down < tree->rear)
    {
        child = child_compare(tree, down * 2, (down * 2) + 1);
        if(child == 0)
            return ;
        if(compare(tree->pElement[down].data, tree->pElement[child].data))
        {
            tmp = tree->pElement[child].data;
            tree->pElement[child].data = tree->pElement[down].data;
            tree->pElement[down].data = tmp;
        }
        else
            break ;
        down = child;
    }   
}

void    Destroy_Heap(BinTree *tree)
{
    free(tree->pElement);
    tree->pElement = NULL;
    free(tree);
    tree = NULL;
}

int main(void)
{
    int n;
    int number, data;
    BinTree *tree;

    printf("Max Elem : ");
    scanf(" %d", &n);
    tree = createBintree(n);
     while (1)
    {
        printf("1 : InsertHeap 2 : RemoveHeap 3 : Display 4 : DeleteAll\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : ");
            scanf(" %d", &data);
            Insert_BinTree(tree, data);
            break;
        case 2:
            Delete_BinTree(tree);
            break;
        case 3:
            display_heap(tree);
            break;
        case 4:
            Destroy_Heap(tree);
            return 0;
        default:
            break;
        }
    }
}