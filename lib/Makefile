##
## EPITECH PROJECT, 2019
## lib_uni
## File description:
## Makefile
##

NAME			=			libmy.a

IDIR			=			include/

SRC_LK			=			lib/ls_add.c	\
							lib/ls_create.c	\
							lib/ls_empty.c	\
							lib/ls_free.c	\
							lib/ls_get.c	\
							lib/ls_len.c	\
							lib/ls_rm.c		\
							lib/ls_set.c	\

SRC				=			\
							lib/add_char.c			\
							lib/alphanumeric.c		\
							lib/char_in_str.c		\
							lib/del_from.c			\
							lib/error.c				\
							lib/fusion_word.c		\
							lib/get_next_line.c		\
							lib/get_stdin.c			\
							lib/isnum.c				\
							lib/my_atoi.c			\
							lib/my_free.c			\
							lib/my_fwr.c			\
							lib/my_malloc.c			\
							lib/my_pow.c			\
							lib/my_putchar.c		\
							lib/my_putnbr.c			\
							lib/my_strdup.c			\
							lib/my_strlen.c			\
							lib/prefix_del.c		\
							lib/replace_in.c		\
							lib/reverse_str.c		\
							lib/str_to_word_array.c	\
							lib/strc.c				\
							lib/word_array_to_str.c	\

OBJ				=			$(SRC:.c=.o)
OBJ_LK			=			$(SRC_LK:.c=.o)

CFLAGS			+=			-I$(IDIR)
CFLAGS			+=			-g
CFLAGS			+=			-Wall -Wextra

all: $(NAME)
		@$(info All lib done)

$(NAME):	$(OBJ) $(OBJ_LK)
		@ar rc -o $(NAME) $(OBJ) $(OBJ_LK)
		@rm -f $(OBJ) $(OBJ_LK)

fclean:
		@rm -f $(NAME)

re: fclean all

nolk: $(OBJ)
	@ar rc -o $(NAME) $(OBJ)
	@$(info Lib without linked list done)