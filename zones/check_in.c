/*
** check_in.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 15:19:44 2017 Killian
** Last update Thu Sep  7 15:27:04 2017 Killian
*/

#include "tekadv.h"

void		check_in(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	zone;

  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  zone = sfCircleShape_getGlobalBounds(displayer->blue_zone);
  if (!sfFloatRect_intersects(&player, &zone, NULL))
    displayer->player->hp -= ZONE_DMG;
}
