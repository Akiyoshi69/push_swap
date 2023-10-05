/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:52:01 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/27 18:54:01 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_return(int *tab)
{
	free(tab);
	return (0);
}

int	free_tab_stack(int *tab, t_stack sta)
{
	free(tab);
	sta = clear_stack(sta);
	return (0);
}

char	**free_return_error(char *temp)
{
	free (temp);
	ft_putendl_fd("Error", 2);
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
