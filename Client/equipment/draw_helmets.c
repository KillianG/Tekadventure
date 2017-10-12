/*
** draw_helmets.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:29:05 2017 Killian
** Last update Mon Oct  2 15:35:36 2017 Killian
*/

#include "tekadv.h"

void	draw_helmets(t_displayer *displayer)
{
  int	i;

  i = -1;
  while (displayer->helmets[++i] != NULL)
    {
      if (!displayer->helmets[i]->is_head)
	sfRenderWindow_drawSprite(displayer->window,
				  displayer->helmets[i]->sprite, NULL);
    }
}
