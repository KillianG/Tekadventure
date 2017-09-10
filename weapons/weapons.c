/*
** weapons.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 09:58:25 2017 Killian
** Last update Thu Sep  7 14:41:48 2017 Killian
*/

#include "tekadv.h"

t_displayer	*init_weapons(t_displayer *displayer)
{
  displayer->weapons[0] = init_weapon(vector2f(100, 100), 0);
  displayer->weapons[1] = init_weapon(vector2f(0, 100), 1);
  displayer->weapons[2] = init_weapon(vector2f(100, 0), 2);
  displayer->weapons[3] = init_weapon(vector2f(200, 50), 4);
  displayer->weapons[NB_WEAPONS] = NULL;
  return (displayer);
}
