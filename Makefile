##
## Makefile for tekadventure in /home/segfault/Desktop/tekaventure
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Wed Sep 27 13:07:15 2017 Marc PEREZ
## Last update Sat Oct  7 14:36:42 2017 ratch7t
##

NAME		=	tekadventure

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRCDIR		=	Client
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
MANDATORYDIR	=	$(SRCDIR)/mandatory
EQUIPMENTDIR	=	$(SRCDIR)/equipment
AMMODIR		=	$(SRCDIR)/ammunitions
CONFIG		=	$(SRCDIR)/config


INCDIR		=	include

RM		=	rm -f

CC		=	gcc
CFLAGS		=	-pipe -march=native -W -Wall -Wextra -Ofast		\
			-I$(INCDIR)
CFLAGS_DEBUG	=	-pipe -march=native -W -Wall -Wextra -Og -g3 -DDEBUG	\
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
			$(WEAPONSDIR)/fist.c			\
			$(WEAPONSDIR)/init_fist.c		\

SRC		+=	$(MENUDIR)/initializer.c		\
			$(MENUDIR)/menu.c			\
			$(MENUDIR)/zombie_file.c			\
			$(MENUDIR)/menu_loop.c			\

SRC		+=	$(ENNEMYDIR)/ennemies.c			\
			$(ENNEMYDIR)/init_ennemy.c		\
			$(ENNEMYDIR)/update_ennemy.c		\
			$(ENNEMYDIR)/draw_ennemies.c		\

SRC		+=	$(HUDDIR)/hp.c				\
			$(HUDDIR)/arrow.c			\
			$(HUDDIR)/ammo.c			\

SRC		+=	$(ZONEDIR)/init_zone.c			\
			$(ZONEDIR)/draw_zone.c			\
			$(ZONEDIR)/update_zone.c		\
			$(ZONEDIR)/check_in.c			\

SRC		+=	$(NETWORKDIR)/client.c			\
			$(NETWORKDIR)/misc.c			\
			$(NETWORKDIR)/packet.c			\

SRC		+=	$(THREADSDIR)/loop_network.c		\
			$(THREADSDIR)/loop_update.c		\
			$(THREADSDIR)/loop_draw.c		\

SRC		+=	$(MANDATORYDIR)/move.c			\

SRC		+=	$(EQUIPMENTDIR)/draw_helmets.c		\
			$(EQUIPMENTDIR)/helmets.c		\
			$(EQUIPMENTDIR)/init_helmet.c		\
			$(EQUIPMENTDIR)/update_helmets.c	\
			$(EQUIPMENTDIR)/drop_helmet.c		\
			$(EQUIPMENTDIR)/change_helmet.c		\

SRC		+=	$(AMMODIR)/ammo.c			\
			$(AMMODIR)/draw_ammo.c			\
			$(AMMODIR)/init_ammo.c			\
			$(AMMODIR)/update_ammo.c		\

SRC		+=	$(CONFIG)/read_config.c			\
			$(CONFIG)/read_file.c			\

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
