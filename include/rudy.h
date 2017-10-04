/*
** rudy.h for tek_menu in /home/ratch7t/Documents/semester_2/tekadventure/rudy
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Thu Aug 31 14:18:33 2017 ratch7t
** Last update Wed Oct  4 23:17:09 2017 Marc PEREZ
*/

#ifndef RUDY_H_
# define RUDY_H_

/*
** Lib
*/

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdlib.h>
# include <stdio.h>

/*
** Macro
*/

# define BACKGROUND "images/Menu_basic.png"
# define NEWGAME "images/Menu_new_game.png"
# define MULTI "images/Menu_multi_player.png"
# define OPTION "images/Menu_options.png"
# define EXIT "images/Menu_exit.png"
# define GAME_NAME "MENU"
# define MOUSE "images/cursor.png"
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

/*
** Structures
*/

typedef struct		s_displayer
{
  sfRenderWindow	*window;
}			t_displayer;

typedef struct		s_sprite
{
  sfSprite		*background;
  sfSprite		*nw_game;
  sfSprite		*multi;
  sfSprite		*option;
  sfSprite		*exit;
  sfSprite		*cursor;
  sfVector2f		mouse_pos;
  sfVector2i		mouse;
}			t_sprite;

/*
** Fonctions
*/

/*
** Menu
*/

void		draw_game(int nb);
sfRenderWindow	*create_window_menu(char *, int, int);
void		menu_loop(t_displayer *, t_sprite *, int);
int		menu(int id);
void		get_mouse_on_screen(t_displayer *, t_sprite *);

/*
** Initializer
*/

sfSprite	*init_sprite_menu(char *);
t_displayer	*init_displayer_menu(void);
t_sprite	*init_str_sprite(void);

/*
** Vector
*/

sfVector2f	vector2f(float, float);

#endif /* !RUDY_H_ */
