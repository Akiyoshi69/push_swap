/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:26:15 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:13:37 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack st)
{
	t_stack	temp;
	int		count;

	count = 0;
	temp = st;
	while (!stack_empty(temp))
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	check_sorted(t_stack st)
{
	t_stack	temp;

	temp = st->next;
	while (!stack_empty(temp))
	{
		if (st->value > temp->value)
		{
			return (1);
		}
		st = st->next;
		temp = st->next;
	}
	return (0);
}
