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

void	swap_stack(t_stack *st, int j)
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
	if (j == 1)
		ft_putendl_fd("sa", 1);
	else if (j == 2)
		ft_putendl_fd("sb", 1);
}

void	ss_stack(t_stack *sta, t_stack *stb)
{
	swap_stack(sta, 3);
	swap_stack(stb, 3);
	ft_putendl_fd("ss", 1);
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
		ft_putendl_fd("pb", 1);
	else
		ft_putendl_fd("pa", 1);
}
