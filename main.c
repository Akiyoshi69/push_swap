/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:18:50 by clora-ro          #+#    #+#             */
/*   Updated: 2022/01/03 14:18:50 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	sta;
	char	**str;

	i = 0;
	str = check_join(ac, av);
	if (!str)
		return (0);
	while (str[i])
		i++;
	sta = new_stack();
	while (i > 1)
	{
		sta = push_stack(sta, check_atoi(str[i - 1]));
		i--;
	}
	sta = push_stack(sta, check_atoi(str[i - 1]));
	if (check_count(ac, sta) == 0)
		return (free_str_stack(str, sta));
	if (check_sorted(sta) != 1)
		return (0);
	choose_sort(&sta);
	sta = clear_stack(sta);
	return (free_str(str));
}
