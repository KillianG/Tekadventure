/*
** update_weapon.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 14:49:15 2017 Killian
** Last update Thu Sep  7 10:07:06 2017 Killian
*/

#include "tekadv.h"

void	update_weapon(t_weapon *weapon, t_displayer *displayer)
{
  weapon->pos.x = weapon->start.x + displayer->player->pos.x;
  weapon->pos.y = weapon->start.y + displayer->player->pos.y;
  sfSprite_setPosition(weapon->sprite, weapon->pos);
}

void	update_weapons(t_displayer *displayer)
{
  int	curr_w;

  curr_w = -1;
  while (displayer->weapons[++curr_w] != NULL)
    update_weapon(displayer->weapons[curr_w], displayer);
}
