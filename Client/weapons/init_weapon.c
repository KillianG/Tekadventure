/*
** init_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 14:37:40 2017 Killian
** Last update Wed Oct  4 15:39:04 2017 Killian
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
  weapon->sprite = init_sprite(AK47, vector2f(pos.x, pos.y), vector2f(0.25, 0.25));
  weapon->damages = 10;
  if (id == 0 && (weapon->damages = AK_DMG))
    weapon->sprite = init_sprite(AK47, vector2f(pos.x, pos.y), vector2f(0.1, 0.1));
  if (id == 1 && (weapon->damages = AUG_DMG))
    weapon->sprite = init_sprite(AUG, vector2f(pos.x, pos.y), vector2f(0.25, 0.25));
  if (id == 2 && (weapon->damages = FAMAS_DMG))
    weapon->sprite = init_sprite(FAMAS, vector2f(pos.x, pos.y), vector2f(0.25, 0.25));
  if (id == 3 && (weapon->damages = M416_DMG))
    weapon->sprite = init_sprite(M416, vector2f(pos.x, pos.y), vector2f(0.25, 0.25));
  if (id == 4 && (weapon->damages = MK14_DMG))
    weapon->sprite = init_sprite(MK14, vector2f(pos.x, pos.y), vector2f(0.25, 0.25));
  return (weapon);
}
