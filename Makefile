##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## my_sokoban
##

SRC 	=	src/main.c	\
			src/display_map.c	\
			src/change_position.c	\
			src/check_win_or_lose.c	\
			src/find_pos_o.c	\
			src/load_map.c	\
			src/lib.c	\
			src/scan_keyboard.c

TEST 	=	Tests/tests_bsq.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

RM		=	rm -rf

CFLAGS = 	-lcurses

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) ./unit_test

re: fclean all

unit_test: fclean all
	$(CC) -o unit_test SRC/lib.c $(TEST) -lcriterion --coverage

run_test:
	./unit_test

.PHONY: all clean fclean re