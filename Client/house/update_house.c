/*
** update_house.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Aug 31 13:41:22 2017 Killian
** Last update Wed Sep  6 12:39:55 2017 Killian
*/

#include "tekadv.h"

void	update_house(t_house *house, t_displayer *displayer)
{
  house->pos.x = house->start.x + displayer->player->pos.x;
  house->pos.y = house->start.y + displayer->player->pos.y;
  sfSprite_setPosition(house->sprite, house->pos);
}
