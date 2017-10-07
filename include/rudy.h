/*
** rudy.h for tek_menu in /home/ratch7t/Documents/semester_2/tekadventure/rudy
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Thu Aug 31 14:18:33 2017 ratch7t
** Last update Sat Oct  7 17:47:10 2017 ratch7t
*/

#ifndef RUDY_H_
# define RUDY_H_

/*
Lib
*/

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*
Macro
*/

# define MENU_STANDARD "images/menu_nz_standard.png"
# define MENU_PLAY "images/menu_nz_play.png"
# define MENU_OPTION "images/menu_nz_option.png"
# define EXIT "images/menu_nz_exit.png"
# define GAME_NAME "MENU"

/*
zombie
*/
# define ZOMBIE_1 "images/zombie/menu_zombie_01.png"
# define ZOMBIE_2 "images/zombie/menu_zombie_02.png"
# define ZOMBIE_3 "images/zombie/menu_zombie_03.png"
# define ZOMBIE_4 "images/zombie/menu_zombie_04.png"
# define ZOMBIE_5 "images/zombie/menu_zombie_05.png"
# define ZOMBIE_6 "images/zombie/menu_zombie_06.png"
# define ZOMBIE_7 "images/zombie/menu_zombie_07.png"
# define ZOMBIE_8 "images/zombie/menu_zombie_08.png"
# define ZOMBIE_9 "images/zombie/menu_zombie_09.png"
# define ZOMBIE_10 "images/zombie/menu_zombie_10.png"
# define ZOMBIE_11 "images/zombie/menu_zombie_11.png"
# define ZOMBIE_12 "images/zombie/menu_zombie_12.png"
# define ZOMBIE_13 "images/zombie/menu_zombie_13.png"
# define ZOMBIE_14 "images/zombie/menu_zombie_14.png"
# define ZOMBIE_15 "images/zombie/menu_zombie_15.png"
# define ZOMBIE_16 "images/zombie/menu_zombie_16.png"
# define ZOMBIE_17 "images/zombie/menu_zombie_17.png"
# define ZOMBIE_18 "images/zombie/menu_zombie_18.png"
# define ZOMBIE_19 "images/zombie/menu_zombie_19.png"
# define ZOMBIE_20 "images/zombie/menu_zombie_20.png"
# define ZOMBIE_21 "images/zombie/menu_zombie_21.png"
# define ZOMBIE_22 "images/zombie/menu_zombie_22.png"
# define ZOMBIE_23 "images/zombie/menu_zombie_23.png"
# define ZOMBIE_24 "images/zombie/menu_zombie_24.png"
# define ZOMBIE_25 "images/zombie/menu_zombie_25.png"
# define ZOMBIE_26 "images/zombie/menu_zombie_26.png"
# define ZOMBIE_27 "images/zombie/menu_zombie_27.png"
# define ZOMBIE_28 "images/zombie/menu_zombie_28.png"
# define ZOMBIE_29 "images/zombie/menu_zombie_29.png"
# define ZOMBIE_30 "images/zombie/menu_zombie_30.png"
# define ZOMBIE_31 "images/zombie/menu_zombie_31.png"
/*
cursor
*/
# define MOUSE "images/cursor.png"

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720

/*
structures
*/

typedef struct		s_displayer
{
  sfRenderWindow	*window;
}			t_displayer;

typedef struct		s_sprite
{
  sfSprite		*background;
  sfSprite		*nw_game;
  sfSprite		*option;
  sfSprite		*exit;
  sfSprite		*cursor;
  sfVector2f		mouse_pos;
  sfVector2i		mouse;
}			t_sprite;

/*
*****fonctions*******
*/

/*
menu
*/

void		draw_game(int);
sfRenderWindow	*create_window_menu(char *, int, int);
int		menu_loop(t_displayer *, t_sprite *, int);
int		menu();
void		get_mouse_on_screen(t_displayer *, t_sprite *);

/*
initializer
*/

sfSprite	*init_sprite_menu(char *);
t_displayer	*init_displayer_menu();
t_sprite	*init_str_sprite();

/*
vector
*/

sfVector2f	vector2f(float, float);

/*
zombie
*/

int		play_zombie(t_displayer *, t_sprite *);

#endif /* !RUDY_H_ */
