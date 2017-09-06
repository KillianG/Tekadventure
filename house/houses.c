/*
** houses.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 12:25:29 2017 Killian
** Last update Wed Sep  6 12:50:24 2017 Killian
*/

#include "tekadv.h"

t_displayer	*init_houses(t_displayer *displayer)
{
  displayer->houses[0] = init_house(vector2f(0, 0), displayer);
  displayer->houses[1] = init_house(vector2f(500, 500), displayer);
  displayer->houses[2] = init_house(vector2f(30, 30), displayer);
  displayer->houses[3] = init_house(vector2f(100, 100), displayer);
  displayer->houses[4] = init_house(vector2f(-10, -10), displayer);
  displayer->houses[NB_HOUSES] = NULL;
  return (displayer);
}
