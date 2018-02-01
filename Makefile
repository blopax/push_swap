# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 14:43:24 by pclement          #+#    #+#              #
#    Updated: 2018/02/01 19:54:51 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CFLAGS = -Wall -Wextra -Werror -c

SRC_CHECKER = ft_do_op.c ft_op.c ft_safe_free.c get_next_line.c\
			  ft_checker.c ft_is_sorted.c ft_create_lst_push_swap.c\
			  ft_is_sorted_bis.c ft_push_utilities.c ft_lst_utilities.c\
			  main_utilities.c ft_op_utilities.c ft_check_doublons.c\
			  ft_med_utilities.c ft_atoi_ps.c

SRC_PUSH_SWAP = ft_op.c ft_quicksort.c ft_is_sorted.c ft_is_sorted_bis.c\
				ft_opti_op_lst_bis.c ft_opti_op_lst.c ft_create_lst_push_swap.c\
				ft_push_swap.c ft_push_utilities.c ft_op_utilities.c\
				ft_sort_recursive.c main_utilities.c\
				ft_quicksort_rotate.c ft_quicksort_swap_utilities.c\
				ft_lst_utilities.c ft_med_utilities.c\
				ft_min_max.c ft_sort_utilities.c ft_safe_free.c\
				ft_check_doublons.c ft_atoi_ps.c

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

all:  $(PUSH_SWAP) $(CHECKER)

$(CHECKER): $(OBJ_CHECKER)
	make -C libft/
	gcc $(OBJ_CHECKER) ./libft/libft.a -o $@

$(%.o):
	gcc $(CFLAGS) %.c

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	make -C libft/
	gcc $(OBJ_PUSH_SWAP) ./libft/libft.a -o $@

$(%.o):
	gcc $(CFLAGS) %.c

clean:
	make -C libft/ clean
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSH_SWAP)

fclean: clean
	make -C libft/ fclean
	rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: clean fclean all re
