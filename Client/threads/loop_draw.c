/*
** loop_draw.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Sat Sep 23 17:10:22 2017 Killian
** Last update Wed Oct  4 23:41:50 2017 Marc PEREZ
*/

#include <unistd.h>
#include "tekadv.h"

void		loop_draw(void *param)
{
  t_displayer	*displayer;

  displayer = (t_displayer *)param;
  sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
  draw_weapons(displayer);
  draw_houses(displayer);
  draw_helmets(displayer);
  draw_ammo(displayer);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->sprite, NULL);
  draw_hand_weapon(displayer);
  continue_shooting(displayer);
  draw_ennemies(displayer);
  draw_players(displayer);
  draw_zone(displayer);
  draw_arrow(displayer);
  sfRenderWindow_drawText(displayer->window, displayer->hp, NULL);
  sfRenderWindow_drawText(displayer->window, displayer->ammunitions, NULL);
  usleep(1000);
}
