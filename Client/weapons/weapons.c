/*
** weapons.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 09:58:25 2017 Killian
** Last update Tue Oct  3 14:04:55 2017 Killian
*/

#include <time.h>
#include "tekadv.h"

t_displayer	*init_weapons(t_displayer *displayer)
{
  int		i;

  i = -1;
  while (++i < NB_WEAPONS)
    {
      displayer->weapons[i] = init_weapon(vector2f(rand() % MAP_SIZEX,
						   rand() % MAP_SIZEY),
					  rand() % 4);
    }
  displayer->weapons[i] = NULL;
  return (displayer);
}
