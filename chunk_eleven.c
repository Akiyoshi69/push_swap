/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_eleven.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:03:53 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:06:23 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_chunk_max_a(t_stack *sta, t_stack *stb, int count, int size_chunk, int index)
{
	int	i;
	int	j;
	int	*chunk;

	i = 0;
	j = stack_lenght(*sta);
	chunk = NULL;
	chunk = altern_chunk(sta, chunk, count);
	if (index == 1)
	{
		while (stack_lenght(*stb) < size_chunk || i < j || i < (j - (size_chunk * count)))
		{
			if (check_chunk(chunk, (*sta)->value, size_chunk) == 1)
				p_stack(sta, stb, 1);
			else
				rr_stack(sta, 1);
			i++;
		}
	}
	else if (index == 2)
	{
		while (i < (j - (count_chunk_eleven(*sta, count) * (count - 2))))
		{
			if (check_chunk(chunk, (*sta)->value, size_chunk) == 1)
				p_stack(sta, stb, 1);
			else
				r_stack(sta, 1);
			i++;
		}
	}
	free (chunk);
}

void	is_chunk_max_b(t_stack *sta, t_stack *stb, int count, int size_chunk, int index)
{
	int	i;
	int	j;
	int	k;
	int	*chunk;

	i = 0;
	j = stack_lenght(*sta);
	k = count_chunk_eleven(*sta, 2);
	chunk = NULL;
	chunk = altern_chunk(sta, chunk, count);
	while (i < j - (size_chunk * (count - 2)) - (k - size_chunk))
	{
		if (check_chunk(chunk, (*sta)->value, size_chunk) == 1)
			p_stack(sta, stb, 1);
		else
		{
			if (index == 1)
				rr_stack(sta, 1);
			else
				r_stack(sta, 1);
		}
		i++;
	}
	free (chunk);
}

void	is_chunk_max(t_stack *sta, t_stack *stb, int count)
{
	int			size_chunk;

	if (count == 2)
		size_chunk = count_chunk_eleven(*sta, 2);
	else
		size_chunk = count_chunk_eleven(*sta, count);
	if (count == 5 || count == 7 || count == 9 || count == 11)
		is_chunk_max_b(sta, stb, count, size_chunk, 1);
	else if (count % 2 == 1)
		is_chunk_max_a(sta, stb, count, size_chunk, 1);
	else if (count == 2)
		is_chunk_max_a(sta, stb, count, size_chunk, 2);
	else
		is_chunk_max_b(sta, stb, count, size_chunk, 2);
}
