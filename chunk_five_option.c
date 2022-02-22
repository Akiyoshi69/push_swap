/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_five_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:08:59 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:06:23 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_chunk(t_stack st, int count)
{
	int	i;
	int	j;

	i = stack_lenght(st);
	j = stack_lenght(st);
	if (count == 5)
	{
		i = 4 * (i / 5);
		i = j - i;
	}
	else
		i = i / 5;
	return (i);
}

int	check_chunk(int *tab, int st, int size_chunk)
{
	int	i;

	i = 0;
	while (i < size_chunk)
	{
		if (tab[i] == st)
			return (1);
		i++;
	}
	return (0);
}

void	is_chunk(t_stack *sta, t_stack *stb, int count)
{
	int		*chunk;
	int		size_chunk;
	int		i;
	int		lenght;

	i = 0;
	lenght = stack_lenght(*sta);
	chunk = NULL;
	chunk = chunk_five(sta, chunk, count);
	size_chunk = count_chunk(*sta, count);
	if (count < 6)
	{
		while (stack_lenght(*stb) < size_chunk || i < lenght)
		{
			if (check_chunk(chunk, (*sta)->value, size_chunk) == 1)
				p_stack(sta, stb, 1);
			else
				rr_stack(sta, 1);
			i++;
		}
	}
	free (chunk);
}
