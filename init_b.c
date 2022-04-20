/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:10 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/20 16:21:25 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	pop_stack(t_stack st)
{
	StackElement	*element;

	if (stack_empty(st))
		return (new_stack());
	element = st->next;
	free (st);
	return (element);
}

int	stack_lenght(t_stack st)
{
	int		lenght;
	t_stack	temp;

	temp = st;
	lenght = 0;
	while (!stack_empty(temp))
	{
		lenght++;
		temp = temp->next;
	}
	return (lenght);
}

t_stack	clear_stack(t_stack st)
{
	while (!stack_empty(st))
		st = pop_stack(st);
	return (new_stack());
}

t_stack	end_stack(t_stack st)
{
	while (st != NULL)
		st = st->next;
	return (st);
}

int	free_return(int *tab)
{
	free (tab);
	return (0);
}
