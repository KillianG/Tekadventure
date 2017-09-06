/*
** interact.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 16:47:58 2017 Killian
** Last update Wed Sep  6 17:00:45 2017 Killian
*/

#include "tekadv.h"

void		interact(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	weapon;

  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  weapon = sfSprite_getGlobalBounds(displayer->weapon->sprite);
  if (sfFloatRect_intersects(&player, &weapon, NULL))
    {
      displayer->player->has_weapon = 1;
      displayer->weapon->is_hand = 1;
    }
}
