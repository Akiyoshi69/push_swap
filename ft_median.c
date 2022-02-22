/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:19:14 by clora-ro          #+#    #+#             */
/*   Updated: 2022/01/03 14:19:14 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*ft_strcalc(t_stack st)
{
	int		*tab;
	int		i;
	int		j;
	t_stack	temp;

	if (!st)
		return (NULL);
	temp = st;
	j = stack_lenght(temp);
	tab = malloc(j * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < j)
	{
		tab[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (tab);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
}

int	ft_median(t_stack st)
{
	int	i;
	int	x;
	int	*tab;

	i = stack_lenght(st);
	tab = ft_strcalc(st);
	ft_sort_int_tab(tab, i);
	x = tab[i / 2];
	free (tab);
	return (x);
}
