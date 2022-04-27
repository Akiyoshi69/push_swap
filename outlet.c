/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:26:15 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/27 18:58:04 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_double_math(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] == '+' || str[i + 1] == '-')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if (ft_check_space(str) == 0)
		return (0);
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
