/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:18:58 by clora-ro          #+#    #+#             */
/*   Updated: 2022/01/03 14:18:58 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_stack *sta)
{
	t_stack	stb;

	stb = NULL;
	if (stack_lenght(*sta) == 2 || stack_lenght(*sta) == 4)
		sort_other(sta, &stb);
	else if (stack_lenght(*sta) < 4)
		sort_three(sta);
	else if (stack_lenght(*sta) < 6)
		sort_five(sta, &stb);
	else if (stack_lenght(*sta) < 101)
		sort_hundred(sta, &stb);
	else
		sort_five_hundred(sta, &stb);
	stb = clear_stack(stb);
}
