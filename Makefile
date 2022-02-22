# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:39:23 by clora-ro          #+#    #+#              #
#    Updated: 2022/02/21 12:54:34 by clora-ro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft

SRCS =	chunk_eleven_option.c	\
		chunk_eleven.c			\
		chunk_five_option.c		\
		chunk_five.c			\
		error_case.c			\
		ft_median.c				\
		init_a.c				\
		init_b.c				\
		main.c					\
		move_a.c				\
		move_b.c				\
		outlet.c				\
		small.c					\
		sort_five_hundred.c		\
		sort_until_hundred.c	\
		sort.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc 

CFLAGS	= 	-Wall -Werror -Wextra

RM		= 	rm -f

CLEAN	=	CLEAN

objs/%.o:%.c push_swap.h libft/libft.h Makefile
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

all		: libft $(NAME)

libft	: 
		$(MAKE) -C libft

$(NAME)	:	$(addprefix objs/, $(OBJS)) 
			$(CC)  $(CFLAGS) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a

clean 	: 
		rm -rf 	objs
		make clean -C libft

fclean	: clean
		$(RM) $(NAME)
		make fclean -C libft

re :	fclean all
		make re -C libft

.PHONY: fclean clean all libft re