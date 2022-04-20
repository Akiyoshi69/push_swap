/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:27:36 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/12 16:47:11 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_stack(t_stack *st, int j)
{
	t_stack	temp;

	if (!*st || !(*st)->next)
		return ;
	temp = *st;
	while (temp->next)
		temp = temp->next;
	temp->next = *st;
	*st = (*st)->next;
	temp->next->next = NULL;
	temp->next->prev = temp;
	if (j == 1)
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
}

void	double_r_stack(t_stack *sta, t_stack *stb)
{
	r_stack(sta, 1);
	r_stack(stb, 2);
	ft_putendl_fd("rr", 1);
}

void	rr_stack(t_stack *st, int j)
{
	t_stack	temp;

	if (!*st || !(*st)->next)
		return ;
	temp = *st;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *st;
	temp->next->prev = temp;
	*st = temp;
	if (j == 1)
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
}

void	double_rr_stack(t_stack *sta, t_stack *stb)
{
	rr_stack(sta, 1);
	rr_stack(stb, 2);
	ft_putendl_fd("rrr", 1);
}
