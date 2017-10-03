/*
** init_zone.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:48:45 2017 Killian
** Last update Tue Oct  3 14:04:22 2017 Killian
*/

#include "tekadv.h"

#include <time.h>

void		init_zone(t_displayer *displayer)
{
  sfCircleShape	*blue;
  sfVector2f	pos;

  pos.x = (rand() % MAP_SIZEX) - RADIUS;
  pos.y = (rand() % MAP_SIZEY) - RADIUS;
  if (pos.x < 0)
    pos.x *= -1;
  if (pos.y < 0)
    pos.y *= -1;
  blue = sfCircleShape_create();
  sfCircleShape_setPosition(blue, pos);
  sfCircleShape_setRadius(blue, 100);
  sfCircleShape_setFillColor(blue, sfTransparent);
  sfCircleShape_setOutlineColor(blue, sfBlue);
  /*sfCircleShape_setOrigin(blue, vector2f(RADIUS, RADIUS));*/
  sfCircleShape_setOutlineThickness(blue, 10);
  displayer->blue_zone = blue;
  displayer->blue_start = pos;
}
