#include "binsearchtree.h"

void    loop(void)
{
    int number, key;

    BinSearchTree *tree;
    BinSearchTreeNode node = {0, 0, 0, 0, 0};
    tree = createBinSearchTree();

    while (1)
    {
        printf("1 : Insert 2 : Remove 3 : Display 4 : DeleteAll\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("key : value = ");
            getchar();
            scanf("%d %c", &node.key, &node.value);
            insertElementBST(tree, node);
            break;
        case 2:
            printf("Remove key : ");
            getchar();
            scanf("%d", &key);
            deleteElementBST(tree, key);
            break;
        case 3:
            levelOrderTraversalBinTree(tree->pRootNode);
            break;
        case 4:
            deleteBinSearchTree(tree);
            return ;
        default:
            break;
        }
    }
}

int main(void)
{
   loop();
   system("leaks BST");
}