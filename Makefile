##
## Makefile for bsq in /root/Delivery/CProg_Elem/CPE_2016_BSQ
##
## Made by root
## Login   <kentin.pratelli@epitech.eu>
## Started on  Tue May  2 13:21:14 2017 root
## Last update Wed Aug 30 18:31:25 2017 Killian
## 

CC      =       gcc -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS  +=      -I include/

NAME    =       TEK

SRCS    =       main.c			\
		screen/draw_screen.c	\
		utils/angle.c		\
		utils/displayer.c	\
		utils/init_sprite.c	\
		utils/rect.c		\
		utils/vectors.c		\
		utils/windows.c		\
		player/update_player.c	\
		player/init_player.c	\
		entries/get_entries.c	\
		entries/move_left.c	\
		entries/move_right.c	\
		entries/move_up.c	\
		entries/move_down.c	\
		utils/map.c

OBJS    =       $(SRCS:.c=.o)


all:            $(NAME)

clean:
		$(RM) $(OBJS)

$(NAME):        $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean re



