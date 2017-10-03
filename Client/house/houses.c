/*
** houses.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 12:25:29 2017 Killian
** Last update Tue Oct  3 14:04:03 2017 Killian
*/

#include <time.h>
#include "tekadv.h"

t_displayer	*init_houses(t_displayer *displayer)
{
  int		i;

  i = -1;
  while (++i < NB_HOUSES)
    {
      displayer->houses[i] = init_house(vector2f(rand() % MAP_SIZEX, rand() % MAP_SIZEY),
				displayer);
    }
  displayer->houses[i] = NULL;
  return (displayer);
}
