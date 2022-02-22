/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:19:02 by clora-ro          #+#    #+#             */
/*   Updated: 2022/01/03 14:19:02 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *st)
{
	t_stack	temp;

	if (!*st || !(*st)->next)
		return ;
	temp = (*st)->next;
	(*st)->next = (*st)->next->next;
	(*st)->next->prev = *st;
	temp->next = *st;
	*st = temp;
	(*st)->next->prev = *st;
}

void	ss_stack(t_stack *sta, t_stack *stb)
{
	swap_stack(sta);
	swap_stack(stb);
}

void	p_stack(t_stack *sta, t_stack *stb, int j)
{
	t_stack	temp;
	t_stack	prev;

	if (!sta || !*sta)
		return ;
	prev = NULL;
	temp = (*sta)->next;
	(*sta)->next = *stb;
	if (stb && *stb)
		(*stb)->prev = *sta;
	*stb = *sta;
	*sta = temp;
	if (*sta)
		(*sta)->prev = NULL;
	if (j == 1)
		printf("pb\n");
	else
		printf("pa\n");
}
