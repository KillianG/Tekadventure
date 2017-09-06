/*
** init_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 14:37:40 2017 Killian
** Last update Wed Sep  6 14:56:34 2017 Killian
*/

#include "tekadv.h"

t_weapon	*init_weapon(sfVector2f pos)
{
  t_weapon	*weapon;

  if ((weapon = malloc(sizeof(t_weapon))) == NULL)
    return (NULL);
  weapon->pos = pos;
  weapon->start = pos;
  weapon->sprite = init_sprite(AK47, vector2f(pos.x, pos.y), vector2f(0.1, 0.1));
  weapon->damages = 10;
  return (weapon);
}
