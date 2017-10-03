/*
** draw_helmets.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:29:05 2017 Killian
** Last update Tue Oct  3 14:39:36 2017 Killian
*/

#include "tekadv.h"

void	draw_ammo(t_displayer *displayer)
{
  int	i;

  i = -1;
  while (displayer->ammo[++i] != NULL)
    {
      if (displayer->ammo[i]->is_ground)
	sfRenderWindow_drawSprite(displayer->window,
				  displayer->ammo[i]->sprite, NULL);
    }
}
