##
## Makefile for tekadv in /home/killian/github/tekaventure
## 
## Made by Killian
## Login   <killian.gardahaut@epitech.eu>
## 
## Started on  Wed Sep  6 15:01:02 2017 Killian
<<<<<<< HEAD
## Last update Mon Sep 25 13:07:51 2017 Killian
=======
## Last update Wed Sep 20 19:39:06 2017 Marc PEREZ
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
##

NAME		=	TEK

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRCDIR		=	.
ENTRIESDIR	=	$(SRCDIR)/entries
HOUSEDIR	=	$(SRCDIR)/house
PLAYERDIR	=	$(SRCDIR)/player
SCREENDIR	=	$(SRCDIR)/screen
UTILSDIR	=	$(SRCDIR)/utils
WEAPONSDIR	=	$(SRCDIR)/weapons
MENUDIR		=	$(SRCDIR)/menu
ENNEMYDIR	=	$(SRCDIR)/ennemy
HUDDIR		=	$(SRCDIR)/HUD
ZONEDIR		=	$(SRCDIR)/zones
NETWORKDIR	=	$(SRCDIR)/network
THREADSDIR	=	$(SRCDIR)/threads


INCDIR		=	include

RM		=	rm -f

CC		=	gcc
<<<<<<< HEAD
CFLAGS		=	-pipe -W -Wall -Wextra -g3 -lm		\
=======
CFLAGS		=	-pipe -march=native -W -Wall -Wextra -Ofast		\
			-I$(INCDIR)
CFLAGS_DEBUG	=	-pipe -march=native -W -Wall -Wextra -Og -g3 -DDEBUG	\
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
			-I$(INCDIR)

LDFLAGS		=	-lcsfml-audio				\
			-lcsfml-graphics			\
			-lcsfml-window				\
			-lcsfml-system				\
			-lm

SRC		=	$(SRCDIR)/main.c

SRC		+=	$(ENTRIESDIR)/get_entries.c		\
			$(ENTRIESDIR)/move_down.c		\
			$(ENTRIESDIR)/move_left.c		\
			$(ENTRIESDIR)/move_up.c			\
			$(ENTRIESDIR)/move_right.c		\
			$(ENTRIESDIR)/interact.c		\

SRC		+=	$(HOUSEDIR)/draw_houses.c		\
			$(HOUSEDIR)/houses.c			\
			$(HOUSEDIR)/init_house.c		\
			$(HOUSEDIR)/update_house.c		\

SRC		+=	$(PLAYERDIR)/init_player.c		\
			$(PLAYERDIR)/update_player.c		\
			$(PLAYERDIR)/players.c			\

SRC		+=	$(UTILSDIR)/angle.c			\
			$(UTILSDIR)/displayer.c			\
			$(UTILSDIR)/init_sprite.c		\
			$(UTILSDIR)/map.c			\
			$(UTILSDIR)/rect.c			\
			$(UTILSDIR)/update.c			\
			$(UTILSDIR)/vectors.c			\
			$(UTILSDIR)/windows.c			\
			$(UTILSDIR)/move_forward.c		\
			$(UTILSDIR)/collide.c			\
			$(UTILSDIR)/my_itoa.c			\

SRC		+=	$(SCREENDIR)/draw_screen.c		\

SRC		+=	$(WEAPONSDIR)/init_weapon.c		\
			$(WEAPONSDIR)/update_weapon.c		\
			$(WEAPONSDIR)/hand_weapon.c		\
			$(WEAPONSDIR)/shoot.c			\
			$(WEAPONSDIR)/draw_weapons.c		\
			$(WEAPONSDIR)/weapons.c			\
			$(WEAPONSDIR)/drop_weapon.c		\

SRC		+=	$(MENUDIR)/initializer.c		\
			$(MENUDIR)/menu.c			\

SRC		+=	$(ENNEMYDIR)/ennemies.c			\
			$(ENNEMYDIR)/init_ennemy.c		\
			$(ENNEMYDIR)/update_ennemy.c		\
			$(ENNEMYDIR)/draw_ennemies.c		\

SRC		+=	$(HUDDIR)/hp.c				\
			$(HUDDIR)/arrow.c			\

SRC		+=	$(ZONEDIR)/init_zone.c			\
			$(ZONEDIR)/draw_zone.c			\
			$(ZONEDIR)/update_zone.c		\
			$(ZONEDIR)/check_in.c			\

SRC		+=	$(NETWORKDIR)/client.c			\
			$(NETWORKDIR)/misc.c			\

SRC		+=	$(THREADSDIR)/loop_network.c		\
			$(THREADSDIR)/loop_update.c		\
			$(THREADSDIR)/loop_draw.c		\


OBJ		=	$(SRC:.c=.o)

all		:	title $(NAME)
			@make -C Server

title		:
			@$(ECHO) $(GREEN)"\tTek"$(TEAL)"Adventure\n"$(DEFAULT)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) &&	\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ &&		\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

clean		:
			@$(RM) $(OBJ)
			@$(ECHO) $(GREEN) "[OK]" $(TEAL) "clean"
			make clean -C Server

fclean		:	clean
			@$(RM) $(NAME)
			@$(ECHO) $(GREEN) "[OK]" $(TEAL) "fclean"
			make fclean -C Server

re		:	fclean all
			make re -C Server

debug		:	CFLAGS = $(CFLAGS_DEBUG)
debug		:	fclean all
			make debug -C Server

.PHONY	: all title clean fclean re
