/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:44:41 by clora-ro          #+#    #+#             */
/*   Updated: 2021/12/20 12:44:41 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	new_stack(void)
{
	return (NULL);
}

int	stack_empty(t_stack st)
{
	if (st == NULL)
		return (1);
	return (0);
}

t_stack	push_stack(t_stack st, long int x)
{
	StackElement	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->value = x;
	element->next = st;
	element->prev = NULL;
	if (st)
		st->prev = element;
	return (element);
}

void	print_stack(t_stack st)
{
	if (stack_empty(st))
	{
		printf("Rien a afficher, la pile est vide.\n");
		return ;
	}
	while (!stack_empty(st))
	{
		printf("[%d]\n", st->value);
		st = st->next;
	}
}
