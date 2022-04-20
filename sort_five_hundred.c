/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:17:29 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/12 17:13:00 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_hundred_a(t_stack *sta, t_stack *stb, int lenn, int count)
{
	int	i;

	i = 0;
	is_chunk_max(sta, stb, count);
	while (i < lenn)
	{
		up_smaller(stb, 2);
		p_stack(stb, sta, 2);
		r_stack(sta, 1);
		i++;
	}
}

void	sort_five_hundred_b(t_stack *sta, t_stack *stb, int len, int count)
{
	int	i;

	i = 0;
	is_chunk_max(sta, stb, count);
	while (i < len)
	{
		up_smaller(stb, 1);
		p_stack(stb, sta, 2);
		i++;
	}
}

t_stack	sort_five_hundred(t_stack *sta, t_stack *stb)
{
	int	i;
	int	len;
	int	lenn;
	int	count;

	i = 0;
	count = 1;
	len = count_chunk_eleven(*sta, count);
	lenn = count_chunk_eleven(*sta, 2);
	while (count < 12)
	{
		if (count == 2)
			sort_five_hundred_a(sta, stb, lenn, count);
		else
			sort_five_hundred_b(sta, stb, len, count);
		count++;
	}
	while (i < len * 5 + lenn)
	{
		r_stack(sta, 1);
		i++;
	}
	return (*sta);
}

t_stack	sort_other(t_stack *sta, t_stack *stb)
{
	if (stack_lenght(*sta) == 2)
	{
		if ((*sta)->value > (*sta)->next->value)
			r_stack(sta, 1);
	}
	if (stack_lenght(*sta) == 4)
	{
		up_smaller_a(sta, 2);
		p_stack(sta, stb, 1);
		sort_three(sta);
		p_stack(stb, sta, 2);
	}
	return (*sta);
}
