/*
** check_in.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 15:19:44 2017 Killian
** Last update Sat Sep  9 14:56:39 2017 Killian
*/

#include "tekadv.h"

int		check_in(t_displayer *displayer)
{
  float		dx;
  float		dy;
  sfVector2f    pos;
  sfVector2f    pos2;
  float		R;

  pos.x = displayer->blue_start.x;
  pos.y = displayer->blue_start.y;
  pos2 = displayer->player->pos;
  pos2.x = (pos2.x * -1) + SCREEN_WIDTH / 2;
  pos2.y = (pos2.y * -1) + SCREEN_HEIGHT / 2;
  dx = abs(pos.x - pos2.x);
  dy = abs(pos.y - pos2.y);
  R = displayer->blue_radius;
  if (dx + dy <= R)
      return (1);
  if (dx > R)
      return (0);
  if (dy > R)
      return (0);
  if (SQUARE(dx) + SQUARE(dy) <= SQUARE(R))
    return (1);
  return (0);
}
