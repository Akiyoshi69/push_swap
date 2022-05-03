/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:10 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/03 13:05:22 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**check_join_2(char *temp, char **str, char **str_b)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (!ft_strlen(str[i]) || ft_check_num(str[i]) == 0)
			return (free_return_error(temp));
		temp = ft_strjoin_free(temp, str[i]);
		if (!temp)
			return (NULL);
		temp = ft_strjoin_free(temp, " ");
		if (!temp)
			return (NULL);
	}
	str_b = ft_split(temp, ' ');
	if (str_b[0] == NULL)
		return (free_return_error(temp));
	free (temp);
	return (str_b);
}
