/*
** draw_zone.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:53:23 2017 Killian
** Last update Thu Sep  7 14:55:50 2017 Killian
*/

#include "tekadv.h"

void	draw_zone(t_displayer *displayer)
{
  sfRenderWindow_drawCircleShape(displayer->window, displayer->blue_zone, NULL);
}
