NAME = libft.a

#compiler
CC = clang
CFLAGS = -Werror -Wall -Wextra

#flags for preprocessor
CPPFLAGS = -I.

#deps
DEPENDENCIES = libft.h Makefile

#srcs
SRC_PATH =
SRC = ft_strcat.c ft_strchr.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strlen.c\
	  ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c\
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
	  ft_putnbr_intmax.c ft_int_size.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	  ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c\
	  ft_count_if.c ft_wstrlen.c ft_wstrnew.c get_next_line.c\

#obj
OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

#disable implicit rules
.SUFFIXES:
.PHONY: clean fclean all re lib_rule

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)


$(OBJ_PATH)%.o: %.c $(DEPENDENCIES)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@$(RM) -R $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all
