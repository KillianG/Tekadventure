/*
** houses.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 12:25:29 2017 Killian
** Last update Sat Oct  7 14:46:10 2017 Killian
*/

#include <time.h>
#include "tekadv.h"

t_displayer	*init_houses(t_displayer *displayer)
{
  int		i;

  i = -1;
  while (++i < NB_HOUSES)
    {
      displayer->houses[i] = init_house(vector2f(300, 300),
				displayer);
    }
  displayer->houses[i] = NULL;
  return (displayer);
}
