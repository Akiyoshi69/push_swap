/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:17:55 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/07 11:17:55 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sort_three(t_stack *sta)
{
	if ((*sta)->value < (*sta)->next->next->value
		&& (*sta)->next->next->value < (*sta)->next->value)
	{
		swap_stack(sta, 1);
		r_stack(sta, 1);
	}
	else if ((*sta)->next->value < (*sta)->value
		&& (*sta)->value < (*sta)->next->next->value)
		swap_stack(sta, 1);
	else if ((*sta)->next->next->value < (*sta)->value
		&& (*sta)->value < (*sta)->next->value)
		rr_stack(sta, 1);
	else if ((*sta)->next->value < (*sta)->next->next->value
		&& (*sta)->next->next->value < (*sta)->value)
		r_stack(sta, 1);
	else if ((*sta)->next->next->value < (*sta)->next->value
		&& (*sta)->next->value < (*sta)->value)
	{
		swap_stack(sta, 1);
		rr_stack(sta, 1);
	}
	return (*sta);
}

t_stack	sort_five(t_stack *sta, t_stack *stb)
{
	up_smaller(sta, 2, 1);
	p_stack(sta, stb, 1);
	up_smaller(sta, 2, 1);
	p_stack(sta, stb, 1);
	sort_three(sta);
	if ((*stb)->value < (*stb)->next->value)
		swap_stack(stb, 2);
	p_stack(stb, sta, 2);
	p_stack(stb, sta, 2);
	return (*sta);
}

void	sort_hundred_a(t_stack *sta, t_stack *stb, int len, int count, int index)
{
	int	i;

	i = 0;
	is_chunk(sta, stb, count);
	while (i < len)
	{
		up_smaller(stb, 1, 2);
		p_stack(stb, sta, 2);
		if (index == 2)
			r_stack(sta, 1);
		i++;
	}
}

t_stack	sort_hundred(t_stack *sta, t_stack *stb)
{
	int		count;
	int		len;
	int		lenn;

	count = 1;
	lenn = count_chunk(*sta, 5);
	len = count_chunk(*sta, count);
	while (count < 6)
	{
		if (count < 4)
			sort_hundred_a(sta, stb, len, count, 1);
		else if (count == 4)
			sort_hundred_a(sta, stb, len, count, 2);
		else
			sort_hundred_a(sta, stb, lenn, count, 2);
		count++;
	}
	return (*sta);
}
