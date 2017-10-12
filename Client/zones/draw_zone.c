/*
** draw_zone.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:53:23 2017 Killian
** Last update Wed Oct  4 23:42:53 2017 Marc PEREZ
*/

#include "tekadv.h"

void	draw_zone(t_displayer *displayer)
{
  sfRenderWindow_drawCircleShape(displayer->window, displayer->blue_zone,
				 NULL);
}
