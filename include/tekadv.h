/*
** tekadv.h for tekadv in /home/killian/github/tekaventure/include
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:16:52 2017 Killian
** Last update Wed Sep  6 13:42:33 2017 Killian
*/

#ifndef TEKADV_H_
# define TEKADV_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <math.h>
# include <stdlib.h>

/* __________ WINDOW UTILS _________ */

# define GAME_NAME "Tekadventure"
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

/* __________ PLAYER UTILS _________ */

# define SPEED 0.2

/* __________ MAP __________ */

# define MAP_SIZEX 3000
# define MAP_SIZEY 3000

/* __________ MATH UTILS _________ */

# define TO_RAD(a) (M_PI * a / 180)
# define SQUARE(a) (a*a)

/* __________ HOUSES UTILS __________ */

# define NB_HOUSES 5

/* _________ SPRITES ________ */

# define BACKGROUND "images/background.jpg"
# define PLAYER "images/players.png"
# define HOUSE "images/house.png"

/* __________ STRUCTURES __________ */

typedef struct		s_house
{
  sfSprite		*sprite;
  sfIntRect		hitbox;
  sfVector2f		pos;
  sfVector2f		start;
}			t_house;

typedef struct          s_player
{
  int                   hp;
  sfVector2f            pos;
  int                   has_weapon;
  sfSprite              *sprite;
  sfIntRect             hitbox;
  int			sprite_pos;
}                       t_player;

typedef struct		s_displayer
{
  sfRenderWindow	*window;
  sfSprite		*map;
  t_player		*player;
  t_house		*houses[NB_HOUSES];
}			t_displayer;

/* __________ FUNCTIONS _________*/

void		draw_screen();
t_displayer	*init_displayer();
sfRenderWindow	*create_window(char *, int, int);
sfSprite	*init_sprite(char *, sfVector2f, sfVector2f);
sfVector2f	vector2f(float, float);
t_player	*update_player(t_player *);
t_player	*init_player();
sfIntRect	int_rect(int, int, int, int);
void		get_entries(t_displayer *);
void		move_left(t_displayer *);
void		move_right(t_displayer *);
void		move_up(t_displayer *);
void		move_down(t_displayer *);
void		update_map(t_displayer *);
t_house		*init_house(sfVector2f, t_displayer *);
t_displayer	*init_houses(t_displayer *);
void		update_house(t_house *, t_displayer *);
void		update(t_displayer *);
int		collide(t_displayer *);

#endif
