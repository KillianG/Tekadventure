/*
** update_zone.c for tekadv.h in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:57:13 2017 Killian
** Last update Thu Sep  7 16:31:51 2017 Killian
*/

#include "tekadv.h"

void		update_zone(t_displayer *displayer)
{
  sfVector2f	pos;

  pos.x = displayer->blue_start.x + displayer->player->pos.x;
  pos.y = displayer->blue_start.y + displayer->player->pos.y;
  if (displayer->blue_radius > 300)
    displayer->blue_radius -= ZONE_SPEED;
  check_in(displayer);
  sfCircleShape_setRadius(displayer->blue_zone, displayer->blue_radius);
  sfCircleShape_setPosition(displayer->blue_zone, pos);
}
