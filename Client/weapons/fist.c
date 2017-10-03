/*
** fist.c for tekadv in /root/Delivery/tekaventure/Client/weapons
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Oct  2 13:08:21 2017 root
** Last update Tue Oct  3 16:53:19 2017 root
*/

#include "tekadv.h"

void		right_fist(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->player->fist->sprite,
		       vector2f(SCREEN_WIDTH/2 + 37, SCREEN_HEIGHT/2 + 10));
  sfSprite_setRotation(displayer->player->fist->sprite, 90);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->fist->sprite,
			    NULL);
}

void		down_fist(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->player->fist->sprite,
		       vector2f(SCREEN_WIDTH/2 + 10, SCREEN_HEIGHT/2 + 50));
  sfSprite_setRotation(displayer->player->fist->sprite, 180);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->fist->sprite,
			    NULL);
}

void		left_fist(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->player->fist->sprite,
		       vector2f(SCREEN_WIDTH/2 - 25, SCREEN_HEIGHT/2 + 31));
  sfSprite_setRotation(displayer->player->fist->sprite, 270);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->fist->sprite,
			    NULL);
}

void		up_fist(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->player->fist->sprite,
		       vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - 34));
  sfSprite_setRotation(displayer->player->fist->sprite, 0);
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->fist->sprite,
			    NULL);
}

void		attack_fist(t_displayer *displayer)
{
  float		angle;

  angle = displayer->player->angle;
  if (displayer->player->has_weapon)
    return ;
  if (angle < 45 || angle >= 315)
    right_fist(displayer);
  else if (angle < 135 && angle >= 45)
    down_fist(displayer);
  else if (angle < 225 && angle >= 135)
    left_fist(displayer);
  else
    up_fist(displayer);
}
