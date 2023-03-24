##
## EPITECH PROJECT, 2022
## B-OOP-400-LYN-4-1-tekspice-tom.desalmand [WSL: Ubuntu]
## File description:
## Makefile
##

CC = g++

CFLAGS	= 	-std=c++20 -Wall -Wextra -Werror -g3

RM		=	rm -f

NAME	=	parrallelJam

SRC		=	$(wildcard source/*.cpp) \
			$(wildcard *.cpp)	\

OBJ		= 	$(SRC:.cpp=.o)

TMP		=	$(wildcard lib/*.gcno) \
			$(wildcard lib/*.gcda) \
			$(wildcard tests/*.gcno) \
			$(wildcard tests/*.gcda) \
			$(wildcard vgcore*) \

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) $(TMP)

re		:	fclean all

tests_run:
	make -C tests all

.PHONY: all clean fclean re tests_run