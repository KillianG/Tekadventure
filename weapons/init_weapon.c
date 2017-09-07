/*
** init_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 14:37:40 2017 Killian
** Last update Thu Sep  7 10:44:33 2017 Killian
*/

#include "tekadv.h"

t_weapon	*init_weapon(sfVector2f pos, int id)
{
  t_weapon	*weapon;

  if ((weapon = malloc(sizeof(t_weapon))) == NULL)
    return (NULL);
  weapon->pos = pos;
  weapon->start = pos;
  weapon->is_hand = 0;
  if (id == 0)
    weapon->sprite = init_sprite(AK47, vector2f(pos.x, pos.y), vector2f(0.3, 0.3));
  else if (id == 1)
    weapon->sprite = init_sprite(AUG, vector2f(pos.x, pos.y), vector2f(0.3, 0.3));
  else if (id == 2)
    weapon->sprite = init_sprite(FAMAS, vector2f(pos.x, pos.y), vector2f(0.3, 0.3));
  else if (id == 3)
    weapon->sprite = init_sprite(M416, vector2f(pos.x, pos.y), vector2f(0.3, 0.3));
  else
    weapon->sprite = init_sprite(AK47, vector2f(pos.x, pos.y), vector2f(0.3, 0.3));
  weapon->damages = 10;
  return (weapon);
}
