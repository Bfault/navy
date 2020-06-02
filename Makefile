##
## EPITECH PROJECT, 2019
## PSU_navy_2019
## File description:
## Makefile
##

NAME		=		navy

IDIR		=		include/
IDIR_MY		=		lib/include/

LDIR		=		lib/
LNAME		=		my

SRC			=		main.c \
					src/signal.c						\
					src/usage.c							\
					src/attack.c						\
					src/receive_attack.c				\
					src/test_file.c						\
					src/test_pid.c						\
					src/game_loop.c						\
					src/open_and_read.c					\
					src/player_1.c						\
					src/player_2.c						\
					src/send_pid.c						\
					src/send_bin.c						\
					src/get_bin.c						\
					src/receive_pid.c					\
					src/draw_pid.c						\
					src/draw_connection.c				\
					src/binary_convert.c				\
					src/set_ship_on_board.c				\

CC			=		cc

OBJ			=		$(SRC:.c=.o)

CFLAGS		+=		-Wall -Wextra -g

CFLAGS		+=		-I$(IDIR) -I$(IDIR_MY)

CFLAGS		+=		-D_XOPEN_SOURCE=700

.SILENT:
all:	$(NAME)
	$(info )
	$(info -----------------------------------------------------)
	$(info |                                                   |)
	$(info |                                                   |)
	$(info |                  compilation 100%                 |)
	$(info |                                                   |)
	$(info |                                                   |)
	$(info -----------------------------------------------------)
	$(info )

$(NAME):	$(OBJ)
	make -C $(LDIR)
	$(CC) -o $(NAME) $(OBJ) -L $(LDIR) -l $(LNAME)

clean:
	rm -f $(OBJ)
	$(info Clean done)

fclean: clean
	make -C $(LDIR) fclean
	rm -f $(NAME)
	$(info All Clean done)

re: fclean all