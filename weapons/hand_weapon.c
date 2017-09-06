/*
** hand_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:09:06 2017 Killian
** Last update Wed Sep  6 21:13:11 2017 Killian
*/

#include "tekadv.h"

void		draw_hand_weapon(t_displayer *displayer)
{
  float		angle;

  angle = get_angle_from_mouse(displayer);
  if (displayer->player->hand == NULL)
    return ;
  sfSprite_setPosition(displayer->player->hand->sprite,
		       vector2f(SCREEN_WIDTH/2 + 10, SCREEN_HEIGHT/2 + 30));
  sfSprite_setRotation(displayer->player->hand->sprite, angle);
  sfSprite_setOrigin(displayer->player->hand->sprite, vector2f(176, 77));
  if (angle < 270 && angle > 90)
    sfSprite_setScale(displayer->player->hand->sprite, vector2f(0.17, -0.17));
  else
    sfSprite_setScale(displayer->player->hand->sprite, vector2f(0.17, 0.17));
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->hand->sprite, NULL);
}
