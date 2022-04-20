/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:09:48 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:09:48 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_element
{
	int					value;
	struct s_element	*next;
	struct s_element	*prev;
}StackElement,	*t_stack;

t_stack			new_stack(void);
int				stack_empty(t_stack st);
StackElement	*push_stack(t_stack st, long int x);

t_stack			pop_stack(t_stack st);
int				stack_lenght(t_stack st);
t_stack			clear_stack(t_stack st);
t_stack			end_stack(t_stack st);
int				free_return(int *tab);

int				check_sorted(t_stack st);
int				count_stack(t_stack st);
int				free_str(char **str);
int				free_str_stack(char **str, t_stack sta);
int				free_tab_stack(int *tab, t_stack sta);

char			**check_join(int count, char **str);
int				check_double(t_stack st);
int				check_count(int count, t_stack st);
long int		check_atoi(const char *str);

void			swap_stack(t_stack *st, int j);
void			ss_stack(t_stack *sta, t_stack *stb);
void			p_stack(t_stack *sta, t_stack *stb, int j);

void			r_stack(t_stack *st, int j);
void			double_r_stack(t_stack *sta, t_stack *stb);
void			rr_stack(t_stack *st, int j);
void			double_rr_stack(t_stack *sta, t_stack *stb);

void			choose_sort(t_stack *sta);

t_stack			sort_three(t_stack *sta);
t_stack			sort_five(t_stack *sta, t_stack *stb);
void			sort_hundred_a(t_stack *sta, t_stack *stb, int len, int count);
void			sort_hundred_b(t_stack *sta, t_stack *stb, int len, int count);
t_stack			sort_hundred(t_stack *sta, t_stack *stb);

void			sort_five_hundred_a(t_stack *sta, t_stack *stb,
					int lenn, int count);
void			sort_five_hundred_b(t_stack *sta, t_stack *stb,
					int len, int count);
t_stack			sort_five_hundred(t_stack *sta, t_stack *stb);
t_stack			sort_other(t_stack *sta, t_stack *stb);

int				pos_median(t_stack st);
int				pos_stack(t_stack st, int value);
int				search_smaller(t_stack st, int *chunk, int ch);
void			up_smaller(t_stack *sta, int i);
void			up_smaller_a(t_stack *sta, int i);

void			ft_swap(int *a, int *b);
int				*ft_strcalc(t_stack st);
void			ft_sort_int_tab(int *tab, int size);
int				ft_median(t_stack st);

int				count_chunk(t_stack st, int count);
int				check_chunk(int *tab, int st, int size_chunk);
void			is_chunk(t_stack *sta, t_stack *stb, int count);

int				*chunk_five(t_stack *st, int *chunk, int count);
int				*chunk_five_a(t_stack *st, int count, int *chunk);
int				*chunk_five_b(t_stack *st, int count, int *chunk);

int				count_chunk_eleven(t_stack st, int count);
int				*altern_chunk_a(t_stack *st, int *chunk, int count);
int				*altern_chunk_b(t_stack *st, int *chunk, int count, int v);
int				*altern_chunk_c(t_stack *st, int *chunk, int count, int v);
int				*altern_chunk(t_stack *st, int *chunk, int count);

void			is_chunk_max_a(t_stack *sta, t_stack *stb,
					int count, int size_chunk);
void			is_chunk_max_b(t_stack *sta, t_stack *stb,
					int count, int size_chunk);
void			is_chunk_max_c(t_stack *sta, t_stack *stb,
					int count, int size_chunk);
void			is_chunk_max_d(t_stack *sta, t_stack *stb,
					int count, int size_chunk);
void			is_chunk_max(t_stack *sta, t_stack *stb, int count);

#endif