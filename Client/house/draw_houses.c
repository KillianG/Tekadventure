/*
** draw_houses.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 14:57:40 2017 Killian
** Last update Wed Sep  6 14:59:35 2017 Killian
*/

#include "tekadv.h"

void		draw_houses(t_displayer *displayer)
{
  int		curr_house;

  curr_house = -1;
  while (displayer->houses[++curr_house] != NULL)
    {
      sfRenderWindow_drawSprite(displayer->window,
				displayer->houses[curr_house]->sprite, NULL);
      update_house(displayer->houses[curr_house], displayer);
    }
}
