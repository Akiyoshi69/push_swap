/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:10 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/27 16:22:39 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	pop_stack(t_stack st)
{
	StackElement	*element;

	if (stack_empty(st))
		return (new_stack());
	element = st->next;
	free (st);
	return (element);
}

int	stack_lenght(t_stack st)
{
	int		lenght;
	t_stack	temp;

	temp = st;
	lenght = 0;
	while (!stack_empty(temp))
	{
		lenght++;
		temp = temp->next;
	}
	return (lenght);
}

t_stack	clear_stack(t_stack st)
{
	while (!stack_empty(st))
		st = pop_stack(st);
	return (new_stack());
}

int	free_return(int *tab)
{
	free(tab);
	return (0);
}

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if (ft_check_double_math(str) == 0)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' ')
			&& (str[i] != '+') && (str[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}
