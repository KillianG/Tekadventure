/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Fri Sep  8 20:07:29 2017 Marc PEREZ
*/

#ifndef GAME_H_
# define GAME_H_

# include <SFML/Graphics.h>

# define NAME_LENGTH	256

typedef struct	s_weapon
{
  sfVector2f	pos;
  sfVector2f	start;
  sfSprite	*sprite;
  int		damages;
  int		is_hand;
}		t_weapon;

typedef struct	s_player
{
  sfVector2f	pos;
  sfVector2f	start;
  sfSprite	*sprite;
  sfIntRect	hitbox;
  char		name[NAME_LENGTH];
  float		hp;
  int		has_weapon;
  t_weapon	*weapon;
  int		sprite_pos;
  int		shoot;
  float		shooting_angle;
}		t_player;

#endif /* !GAME_H_ */
