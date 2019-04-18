##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## script for compil all your lib
##


SRC	=	src/my_getnbr_i.c	\
		src/my_printf.c	\
		src/my_printf1.c	\
		src/my_printf2.c	\
		src/my_put_nbr.c	\
		src/my_put_nbr_evol.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_putstr_flags.c	\
		src/my_strlen.c

CFLAGS	+=	-Wall -Wextra -I

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
