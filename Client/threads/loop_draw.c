/*
** loop_draw.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Sat Sep 23 17:10:22 2017 Killian
** Last update Sat Oct  7 18:51:00 2017 Killian
*/

#include <unistd.h>
#include "tekadv.h"

void		loop_draw(void *param)
{
  t_displayer	*displayer;

  displayer = (t_displayer *)param;
  sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
  sfRenderWindow_drawSprite(displayer->window, displayer->map1, NULL);
  draw_weapons(displayer);
  draw_helmets(displayer);
  draw_ammo(displayer);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->sprite, NULL);
  draw_hand_weapon(displayer);
  continue_shooting(displayer);
  draw_players(displayer);
  sfRenderWindow_drawSprite(displayer->window, displayer->map2, NULL);
  draw_zone(displayer);
  draw_arrow(displayer);
  sfRenderWindow_drawText(displayer->window, displayer->hp, NULL);
  sfRenderWindow_drawText(displayer->window, displayer->ammunitions, NULL);  
  usleep(1000);
}
