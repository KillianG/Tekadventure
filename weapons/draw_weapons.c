/*
** draw_weapons.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 10:03:57 2017 Killian
** Last update Thu Sep  7 10:10:44 2017 Killian
*/

#include "tekadv.h"

void	draw_weapons(t_displayer *displayer)
{
  int	curr_w;

  curr_w = -1;
  while (displayer->weapons[++curr_w])
    {
      if (!displayer->weapons[curr_w]->is_hand)
	sfRenderWindow_drawSprite(displayer->window,
				  displayer->weapons[curr_w]->sprite,
				  NULL);
    }
}
