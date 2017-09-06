##
## Makefile for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure
## 
## Made by ratch7t
## Login   <rudy.simon@epitech.eu>
## 
## Started on  Wed Sep  6 16:19:25 2017 ratch7t
## Last update Wed Sep  6 16:20:59 2017 ratch7t
##

CC      =       gcc -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS  +=      -I ./inc/

NAME    =       Menu

SRCS    =       src/main.c		\
		src/menu.c		\
		src/initializer.c	\
		src/vector.c

OBJS    =       $(SRCS:.c=.o)


all:            $(NAME)

clean:
		$(RM) $(OBJS)

$(NAME):        $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re



