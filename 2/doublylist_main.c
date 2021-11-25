/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:52:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/25 17:49:54 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(DoublyList* pList)
{
	DoublyListNode *tmp;

	if(!pList)
		return ;
	tmp = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		tmp = tmp->pRLink;
		printf("%d\n", tmp->data);
		
	}
}

int		main(void)
{
	int len = 0;
	int position = 0;
	char c;
	DoublyList *temp;
	DoublyListNode *curr;
	DoublyListNode node0 = {0, 0, 0};

	temp = createDoublyList();
	
	while(1)
	{
		printf("put Add Remove Get Print Length Clear Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addDLElement(temp, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeDLElement(temp, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getDLElement(temp, position);
			printf("%d\n", curr->data);
			break;
		case 'P':
			print_list(temp);
			break;
		case 'L':
			len = getDoublyListLength(temp);
			printf("%d\n", len);
			break;
		case 'C':
			clearDoublyList(temp);
			break;
		case 'D':
			deleteDoublyList(temp);
			break;
		default:
			break;
		}
	}
	if(temp)
		deleteDoublyList(temp);
	system("leaks a.out");
}