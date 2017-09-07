/*
** drop_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 10:14:37 2017 Killian
** Last update Thu Sep  7 10:57:38 2017 Killian
*/

#include "tekadv.h"

void		drop_weapon(t_displayer *displayer)
{
  sfVector2f	pos;

  pos.x = (displayer->player->pos.x * -1) + SCREEN_WIDTH/2;
  pos.y = (displayer->player->pos.y * -1) + SCREEN_HEIGHT/2;
  if (!displayer->player->has_weapon)
    return ;
  displayer->player->has_weapon = 0;
  displayer->player->weapon->pos = pos;
  displayer->player->weapon->start = pos;
  displayer->player->weapon->is_hand = 0;
  sfSprite_setScale(displayer->player->weapon->sprite, vector2f(0.3, 0.3));
  sfSprite_setRotation(displayer->player->weapon->sprite, 0);
  displayer->player->weapon = NULL;
}
