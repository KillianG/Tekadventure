/*
** tekadv.h for tekadv in /home/killian/github/tekaventure/include
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:16:52 2017 Killian
** Last update Wed Oct  4 17:19:31 2017 Killian
*/

#ifndef TEKADV_H_
# define TEKADV_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/* __________ WINDOW UTILS _________ */

# define GAME_NAME "Tekadventure"
# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720
# define FONT "images/font.ttf"

/* __________ PLAYER UTILS _________ */

# define SPEED 0.4
# define RADIUS 3000
# define ZONE_DMG 0.001
# define ZONE_SPEED 0.00005

/* __________ MAP __________ */

# define MAP_SIZEX 4000
# define MAP_SIZEY 4000

/* __________ MATH UTILS _________ */

# define TO_RAD(a) (M_PI * a / 180)
# define SQUARE(a) (a*a)

/* __________ HOUSES UTILS __________ */

# define NB_HOUSES 10

/* _________ SPRITES ________ */

# define BACKGROUND "images/background.jpg"
# define PLAYER "images/player.png"
# define PLAYERT1 "images/playert1.png"
# define PLAYERT2 "images/playert2.png"
# define PLAYERT3 "images/playert3.png"
# define PLAYERT0POING "images/playert0poing.png"
# define PLAYERT1POING "images/playert1poing.png"
# define PLAYERT2POING "images/playert2poing.png"
# define PLAYERT3POING "images/playert3poing.png"
# define TEST "images/players1.png"
# define HOUSE "images/house.png"
# define AK47 "images/ak47.png"
# define BULLET "images/bullet.png"
# define AUG "images/aug.png"
# define FAMAS "images/Famas.png"
# define M416 "images/M416.png"
# define MK14 "images/mk14.png"
# define PKP "images/PKP.png"
# define ARROW "images/blue_arrow.png"
# define HELMET1 "images/helmet1.png"
# define HELMET2 "images/helmet2.png"
# define HELMET3 "images/helmet3.png"
# define AMMO "images/ammo.png"
# define FIST "images/fist.png"

/* __________ WEAPONS UTILS __________*/

# define NB_WEAPONS 30
# define AK_DMG 15
# define AUG_DMG 13
# define FAMAS_DMG 5
# define M416_DMG 20
# define MK14_DMG 30

/* __________ ENNEMY UTILS _________ */

# define NB_ENNEMY 2
# define ENNEMY "images/Ganon.png"

/* ________ EQUIPMENT UTILS ________*/

# define NB_HELMET 20
# define HP_HELMET 20
# define NB_AMMO 20

/* __________ STRUCTURES __________ */

typedef struct		s_packet
{
  int			id;
  sfVector2f		pos;
  int			health;
}			t_packet;

typedef struct          s_fist
{
  sfVector2f            pos;
  sfSprite              *sprite;
  int                   damages;
}                       t_fist;

typedef struct		s_ammo
{
  sfVector2f		pos;
  sfVector2f		start;
  sfSprite		*sprite;
  int			amount;
  int			is_ground;
}			t_ammo;

typedef struct		s_helmet
{
  sfVector2f		pos;
  sfVector2f		start;
  sfSprite		*sprite;
  int			level;
  int			is_head;
}			t_helmet;

typedef struct		s_weapon
{
  sfVector2f		pos;
  sfVector2f		start;
  sfSprite		*sprite;
  int			damages;
  int			is_hand;
}			t_weapon;

typedef struct		s_house
{
  sfSprite		*sprite;
  sfIntRect		hitbox;
  sfVector2f		pos;
  sfVector2f		start;
}			t_house;

typedef struct          s_ennemy
{
  int                   hp;
  sfVector2f            pos;
  sfVector2f		start;
  sfSprite              *sprite;
}                       t_ennemy;

typedef struct          s_player
{
  int			ammos;
  int			id;
  float                 hp;
  sfVector2f            pos;
  int                   has_weapon;
  sfSprite              *sprite;
  sfIntRect             hitbox;
  t_weapon		*weapon;
  int			sprite_pos;
  int			shoot;
  float			angle;
  float			shooting_angle;
  t_fist		*fist;
  t_helmet		*helmet;
}                       t_player;

typedef struct		s_displayer
{
  t_helmet		*helmets[NB_HELMET + 1];
  sfSprite		*arrow;
  float			blue_radius;
  sfVector2f		blue_start;
  sfCircleShape		*blue_zone;
  sfSprite		*bullet;
  sfRenderWindow	*window;
  sfSprite		*map;
  t_player		*player;
  t_house		*houses[NB_HOUSES + 1];
  t_weapon		*weapons[NB_WEAPONS + 1];
  t_ennemy		*ennemies[NB_ENNEMY + 1];
  sfText		*hp;
  t_ammo		*ammo[NB_AMMO + 1];
  t_packet		**players;
  t_packet		*received;
  sfText		*ammunitions;
}			t_displayer;

/* __________ FUNCTIONS _________*/

void		draw_game();
t_displayer	*init_displayer(int);
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
t_weapon	*init_weapon();
void		draw_houses(t_displayer *);
void		update_weapon(t_weapon *, t_displayer *);
void		interact(t_displayer *);
int		menu(int);
void		draw_hand_weapon(t_displayer *);
float		get_angle_from_mouse(t_displayer *);
sfVector2f	move_forward(sfVector2f, float, float);
void		shoot(t_displayer *);
void		continue_shooting(t_displayer *);
t_displayer	*init_weapons(t_displayer *);
void		update_weapons(t_displayer *);
void		draw_weapons(t_displayer *);
void		drop_weapon(t_displayer *);
void		init_fist(t_displayer *);
void		check_fist_hit(t_displayer *);
void		attack_fist(t_displayer *);
t_ennemy	*init_ennemy(sfVector2f);
void		init_ennemies(t_displayer *);
void		draw_ennemies(t_displayer *);
void		update_ennemies(t_displayer *);
char		*my_itoa(int);
void		init_hp(t_displayer *);
void		update_hp(t_displayer *);
void		init_zone(t_displayer *);
void		draw_zone(t_displayer *);
void		update_zone(t_displayer *);
int		check_in(t_displayer *);
float		get_angle_from_pos(sfVector2f);
void		init_arrow(t_displayer *);
void		draw_arrow(t_displayer *);
int		send_data(t_packet *);
t_packet	*receive_data(void);
void		init_players(t_displayer *);
int		init_connection(char *, char *);
void		add_players(t_displayer *);
void		loop_network(void *);
void		draw_players(t_displayer *);
void		loop_update(void *);
void		loop_draw(void *);
void		move_player_mouse(t_displayer *);
void		init_helmets(t_displayer *);
t_helmet	*init_helmet(sfVector2f, int);
void		update_helmets(t_displayer *);
void		draw_helmets(t_displayer *);
void		interact_weapon(t_displayer *);
void		interact_equipment(t_displayer *);
void		interact_ammo(t_displayer *);
void		drop_helmet(t_displayer *);
t_ammo		*init_ammo(sfVector2f, int);
void		init_ammos(t_displayer *);
void		draw_ammo(t_displayer *);
void		update_ammos(t_displayer *);
void		init_ammo_text(t_displayer *);
void		update_ammo_text(t_displayer *);
t_packet	*new_packet(t_player *);

#endif
