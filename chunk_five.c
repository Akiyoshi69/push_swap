/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:47:31 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:06:23 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*chunk_five(t_stack *st, int *chunk, int count)
{
	if (!st || !*st)
		return (NULL);
	chunk = malloc(sizeof(int) * count_chunk(*st, count));
	if (!chunk)
		return (NULL);
	if (count == 5)
		chunk = chunk_five_a(st, count, chunk, 1);
	else
		chunk = chunk_five_a(st, count, chunk, 2);
	return (chunk);
}

int	*chunk_five_a(t_stack *st, int count, int *chunk, int index)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = stack_lenght(*st);
	tab = ft_strcalc(*st);
	ft_sort_int_tab(tab, len);
	while (i < count_chunk(*st, count))
	{
		if (index == 1)
			chunk[i] = tab[i + ((count - 1) * count_chunk(*st, count - 1))];
		else if (index == 2)
			chunk[i] = tab[i + ((count - 1) * count_chunk(*st, count))];
		i++;
	}
	free (tab);
	return (chunk);
}
