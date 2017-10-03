/*
** hand_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:09:06 2017 Killian
** Last update Mon Oct  2 13:33:07 2017 root
*/

#include "tekadv.h"

void		draw_hand_weapon(t_displayer *displayer)
{
  float		angle;

  angle = displayer->player->angle;
  if (displayer->player->weapon == NULL)
    return ;
  sfSprite_setPosition(displayer->player->weapon->sprite,
		       vector2f(SCREEN_WIDTH/2 + 10, SCREEN_HEIGHT/2 + 30));
  sfSprite_setRotation(displayer->player->weapon->sprite, angle);
  sfSprite_setOrigin(displayer->player->weapon->sprite, vector2f(87, 25));
  if (angle < 270 && angle > 90)
    sfSprite_setScale(displayer->player->weapon->sprite, vector2f(0.5, -0.5));
  else
    sfSprite_setScale(displayer->player->weapon->sprite, vector2f(0.5, 0.5));
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->weapon->sprite, NULL);
}
