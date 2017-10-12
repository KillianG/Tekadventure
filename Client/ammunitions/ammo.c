/*
** helmets.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 13:59:16 2017 Killian
** Last update Wed Oct  4 14:03:19 2017 Killian
*/

#include <time.h>
#include "tekadv.h"

void		init_ammos(t_displayer *displayer)
{
  int		i;

  i = 0;
  while (i < NB_AMMO)
    {
      displayer->ammo[i++] = init_ammo(vector2f(rand() % MAP_SIZEX,
						     rand() % MAP_SIZEY),
					    rand() % 20 + 2);
    }
  displayer->ammo[i] = NULL;
}
