/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:18:46 by clora-ro          #+#    #+#             */
/*   Updated: 2022/01/03 14:18:46 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_median(t_stack st)
{
	int	i;

	i = stack_lenght(st);
	if (i % 2 == 1)
	{
		return (i / 2 + 1);
	}
	else
	{
		return (i / 2);
	}
}

int	pos_stack(t_stack st, int value)
{
	int	i;

	i = 0;
	while (i < stack_lenght(st))
	{
		if (st->value == value)
		{
			return (i);
		}
		st = st->next;
		i++;
	}
	return (-1);
}

int	search_smaller(t_stack st, int *chunk, int ch)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = chunk[0];
	while (i < stack_lenght(st))
	{
		if (ch == 1 && min < chunk[i])
		{
			min = chunk[i];
			j = i;
		}
		else if (ch == 2 && min > chunk[i])
		{
			min = chunk[i];
			j = i;
		}
		i++;
	}
	free (chunk);
	return (j);
}

void	up_smaller(t_stack *sta, int i)
{
	int	roll;
	int	pos;

	if (!sta || !*sta)
		return ;
	pos = search_smaller(*sta, ft_strcalc(*sta), i);
	if (pos + 1 > pos_median(*sta))
	{
		roll = stack_lenght(*sta) - search_smaller(*sta, ft_strcalc(*sta), i);
		while (roll > 0)
		{
			rr_stack(sta, 2);
			roll--;
		}	
	}
	else
	{
		roll = search_smaller(*sta, ft_strcalc(*sta), i);
		while (roll > 0)
		{
			r_stack(sta, 2);
			roll--;
		}
	}
}
