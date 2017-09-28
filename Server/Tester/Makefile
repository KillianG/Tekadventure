##
## Makefile for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Fri Aug 25 13:40:52 2017 Marc PEREZ
## Last update Thu Sep 28 12:33:15 2017 Marc PEREZ
##

NAME		=	tester

CC		=	gcc

CFLAGS		=	-pipe -march=native -Ofast -W -Wall -Wextra

CFLAGS_DEBUG	=	-pipe -march=native -Og -g3 -DDEBUG -W -Wall -Wextra

LDLIBS		=	-levent

CPPFLAGS	+=	-I ./inc

RM		=	rm -f

SRCS		=						\
		src/main.c					\
		src/misc.c					\
		src/client.c					\

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
