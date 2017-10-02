/*
** interact.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 16:47:58 2017 Killian
** Last update Thu Sep  7 11:03:36 2017 Killian
*/

#include "tekadv.h"

void		interact(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	weapon;
  int		curr_w;

  curr_w = -1;
  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  while (displayer->weapons[++curr_w] != NULL)
    {
      weapon = sfSprite_getGlobalBounds(displayer->weapons[curr_w]->sprite);
      if (sfFloatRect_intersects(&player, &weapon, NULL))
	{
	  drop_weapon(displayer);
	  displayer->player->has_weapon = 1;
	  displayer->player->weapon = displayer->weapons[curr_w];
	  displayer->weapons[curr_w]->is_hand = 1;
	  sfSleep(sfMilliseconds(250));
	  break;
	}
    }
}
