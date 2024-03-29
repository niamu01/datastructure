/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:52:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/25 18:46:37 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_list.h"
#include <stdio.h>

void print_list(ListNode *curr)
{
	while(curr)
	{
		printf("%d\n", curr->data);
		curr = curr->pLink;
	}
}

int		main(void)
{
	int len = 0;
	int position = 0;
	char c;
	LinkedList *temp;
	ListNode *curr;
	ListNode node0 = {0, 0};

	temp = createLinkedList();
	
	while(1)
	{
		printf("put Add Remove Get Print Length Clear Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addLLElement(temp, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeLLElement(temp, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getLLElement(temp, position);
			printf("%d\n", curr->data);
			break;
		case 'P':
			print_list(temp->headerNode.pLink);
			break;
		case 'L':
			len = getLinkedListLength(temp);
			printf("%d\n", len);
			break;
		case 'C':
			clearLinkedList(temp);
			break;
		case 'D':
			deleteLinkedList(temp);
			break;
		case 'V':
			reverseLinkedList(temp);
			print_list(temp->headerNode.pLink);
			reverseLinkedList(temp);
			break;
		default:
			break;
		}
	}
	if(temp)
		deleteLinkedList(temp);
	system("leaks a.out");
}