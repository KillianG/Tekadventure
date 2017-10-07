/*
** arrow.c for tekadv in /home/killian/github/tekaventure/HUD
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 15:37:13 2017 Killian
** Last update Sat Oct  7 15:02:57 2017 Killian
*/

#include "tekadv.h"

void		draw_arrow(t_displayer *displayer)
{
  sfVector2f	pos;

  pos = sfCircleShape_getPosition(displayer->blue_zone);
  sfSprite_setRotation(displayer->arrow, get_angle_from_pos(pos));
  if (!check_in(displayer))
    {
      displayer->player->hp -= ZONE_DMG;
      sfRenderWindow_drawSprite(displayer->window, displayer->arrow, NULL);
    }
}

void		init_arrow(t_displayer *displayer)
{
  sfSprite	*arrow;

  arrow = init_sprite(ARROW, vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
		      vector2f(0.5, 0.5));
  sfSprite_setOrigin(arrow, vector2f(0, -50));
  displayer->arrow = arrow;
}
