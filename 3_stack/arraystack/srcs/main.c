#include "arraystack.h"

void	delete_test()
{
	ArrayStack *as = 0;
	ArrayStackNode ele;

	ele.data = 3;
	as = createArrayStack(10);
	for (int i = 0; i < 3; i++)
		pushAS(as, ele);
	deleteArrayStack(as);
}

int		main(void)
{
	char c;
	ArrayStack *as = 0;
	ArrayStackNode node;
	ArrayStackNode *pop;
	node.data = 0;
	while(1)
	{
		printf("put Create Push pOp pEek Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'C':
			as = createArrayStack(10);
			break;
		case 'P':
			printf("put node : ");
			scanf(" %c", &c);
			node.data = c;
			pushAS(as, node);
			break;
		case 'O':
			pop = popAS(as);
			if (pop)
				printf("%c\n", pop->data);
			break;
		case 'E':
			pop = peekAS(as);
			if (pop)
				printf("%c\n", pop->data);
			break;
		case 'D':
			delete_test();
			system("leaks arraystack");
			//leaks은 같은함수면 못잡는 문제가 있어 이렇게 함 (valgrid)
			break;
		case 'Y':
			displayStack(as);
			break;
		default:
			break;
		}
	}
}
