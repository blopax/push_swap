CHECKER = checker
PUSH_SWAP = push_swap

#compiler
CC = clang
CFLAGS = -Werror -Wall -Wextra

#flags for preprocessor
CPPFLAGS = -Iincludes/ -Ilibft/
LFLAGS = -Llibft -lft

#deps
DEPENDENCIES = includes/header.h Makefile

#libs
LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

#srcs
SRC_PATH =
SRC_CHECKER = ft_do_op.c ft_op.c ft_safe_free.c\
			  ft_checker.c ft_is_sorted.c ft_create_lst_push_swap.c\
			  ft_is_sorted_bis.c ft_push_utilities.c ft_lst_utilities.c\
			  main_utilities.c ft_op_utilities.c ft_check_doublons.c\
			  ft_med_utilities.c ft_atoi_ps.c\

SRC_PUSH_SWAP = ft_op.c ft_quicksort.c ft_is_sorted.c ft_is_sorted_bis.c\
				ft_opti_op_lst.c ft_create_lst_push_swap.c\
				ft_push_swap.c ft_push_utilities.c ft_op_utilities.c\
				ft_sort_recursive.c main_utilities.c ft_check_doublons.c\
				ft_quicksort_rotate.c ft_quicksort_swap_utilities.c\
				ft_lst_utilities.c ft_med_utilities.c ft_atoi_ps.c\
				ft_min_max.c ft_sort_utilities.c ft_safe_free.c\


#obj
OBJ_PATH = obj/
OBJ_CHECKER_NAME = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP_NAME = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(addprefix $(OBJ_PATH), $(OBJ_CHECKER_NAME))
OBJ_PUSH_SWAP = $(addprefix $(OBJ_PATH), $(OBJ_PUSH_SWAP_NAME))

#disable implicit rules
.SUFFIXES:
.PHONY: clean fclean all re

all: $(PUSH_SWAP) $(CHECKER)

$(CHECKER): $(OBJ_CHECKER)
	@echo "Compiling checker"
	@$(CC) $(LFLAGS) $(OBJ_CHECKER) -o $@

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@echo "Compiling push_swap"
	@$(CC) $(LFLAGS) $(OBJ_PUSH_SWAP) -o $@

$(OBJ_PATH)%.o: %.c $(DEPENDENCIES) $(LIB)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB): libft/libft.h libft/*.c libft/Makefile
	@echo "Compiling library"
	@$(MAKE) -C libft/

clean:
	@echo "Removing objects"
	@$(MAKE) -C libft/ clean
	@$(RM) $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	@$(RM) -R $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@echo "Removing binary"
	@$(MAKE) -C libft/ fclean
	@$(RM) $(CHECKER) $(PUSH_SWAP)

re:
	@echo "Recompiling"
	@$(MAKE) fclean
	@$(MAKE) all
