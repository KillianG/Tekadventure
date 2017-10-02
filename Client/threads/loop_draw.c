/*
** loop_draw.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Sat Sep 23 17:10:22 2017 Killian
** Last update Sat Sep 23 17:43:58 2017 Killian
*/

#include "tekadv.h"

void	*loop_draw(t_displayer *displayer)
{
  sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
  draw_weapons(displayer);
  draw_houses(displayer);
  sfRenderWindow_drawSprite(displayer->window, displayer->player->sprite, NULL);
  draw_hand_weapon(displayer);
  continue_shooting(displayer);
  draw_ennemies(displayer);
  draw_players(displayer);
  draw_zone(displayer);
  draw_arrow(displayer);
  sfRenderWindow_drawText(displayer->window, displayer->hp, NULL);
  usleep(1000);
}
