/*
** helmet.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:13:43 2017 Killian
** Last update Tue Oct  3 14:44:35 2017 Killian
*/

#include "tekadv.h"

t_ammo		*init_ammo(sfVector2f pos, int amount)
{
  t_ammo	*ammo;

  if ((ammo = malloc(sizeof(ammo))) == NULL)
    return (NULL);
  ammo->pos = pos;
  ammo->start = pos;
  ammo->sprite = init_sprite(AMMO, pos, vector2f(0.1, 0.1));
  ammo->amount = amount;
  ammo->is_ground = 1;
  return (ammo);
}
