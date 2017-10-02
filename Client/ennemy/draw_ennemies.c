/*
** draw_ennemies.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:34:47 2017 Killian
** Last update Thu Sep  7 14:29:13 2017 Killian
*/

#include "tekadv.h"

void	draw_ennemies(t_displayer *displayer)
{
  int	curr_e;

  curr_e = -1;
  while (displayer->ennemies[++curr_e] != NULL)
    {
      if (displayer->ennemies[curr_e]->hp > 0)
	sfRenderWindow_drawSprite(displayer->window,
				  displayer->ennemies[curr_e]->sprite, NULL);
    }
}
