##
## Makefile for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Fri Aug 25 13:40:52 2017 Marc PEREZ
## Last update Thu Sep  7 22:25:46 2017 Marc PEREZ
##

NAME		=	../cli

CC		=	gcc

CFLAGS		=	-pipe -march=native -fopenmp -Ofast -W -Wall -Wextra

CFLAGS_DEBUG	=	-Og -g3 -DDEBUG -W -Wall -Wextra

CPPFLAGS	+=	-I ./inc -I ./utils/GNL

RM		=	rm -f

SRCS		=						\
		src/core/main.c					\
		utils/GNL/GNL.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

debug:	CFLAGS=$(CFLAGS_DEBUG)
debug:	re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
