/*
** init_zone.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:48:45 2017 Killian
** Last update Sun Oct  8 18:37:50 2017 Killian
*/

#include "tekadv.h"

#include <time.h>

void		init_zone(t_displayer *displayer)
{
  sfCircleShape	*blue;
  sfVector2f	pos;

  pos.x = (MAP_SIZEX) - RADIUS;
  pos.y = (MAP_SIZEY) - RADIUS;
  blue = sfCircleShape_create();
  sfCircleShape_setPosition(blue, pos);
  sfCircleShape_setRadius(blue, 1000);
  sfCircleShape_setFillColor(blue, sfTransparent);
  sfCircleShape_setOutlineColor(blue, sfBlue);
  sfCircleShape_setOutlineThickness(blue, 10);
  displayer->blue_zone = blue;
  displayer->blue_start = pos;
}
