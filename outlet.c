/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:26:15 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/27 14:24:21 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack st)
{
	t_stack	temp;
	int		count;

	count = 0;
	temp = st;
	while (!stack_empty(temp))
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	check_sorted(t_stack st)
{
	t_stack	temp;

	temp = st->next;
	while (!stack_empty(temp))
	{
		if (st->value > temp->value)
			return (1);
		st = st->next;
		temp = st->next;
	}
	return (0);
}

int	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	free_str_stack(char **str, t_stack sta)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	sta = clear_stack(sta);
	return (0);
}

int	free_tab_stack(int *tab, t_stack sta)
{
	free(tab);
	sta = clear_stack(sta);
	return (0);
}
