##
## Makefile for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Fri Aug 25 13:40:52 2017 Marc PEREZ
<<<<<<< HEAD
## Last update Mon Sep 25 13:07:26 2017 Killian
=======
## Last update Wed Sep 20 19:17:53 2017 Marc PEREZ
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
##

NAME		=	../serv

CC		=	gcc

CFLAGS		=	-pipe -march=native -fopenmp -Ofast -W -Wall -Wextra

CFLAGS_DEBUG	=	-pipe -march=native -Og -g3 -DDEBUG -W -Wall -Wextra

LDLIBS		=	-levent

CPPFLAGS	+=	-I ./inc

RM		=	rm -f

SRCS		=						\
		src/core/main.c					\
		src/core/socket.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 @$(CC) $(LDLIBS) -o $(NAME) $(OBJS)

debug:	CFLAGS=$(CFLAGS_DEBUG)
debug:	re

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
