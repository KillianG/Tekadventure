/*
** map.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:07:08 2017 Killian
** Last update Thu Oct  5 15:05:56 2017 Killian
*/

#include "tekadv.h"

void	update_map(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->map, displayer->player->pos);
  sfSprite_setPosition(displayer->map1, displayer->player->pos);
  sfSprite_setPosition(displayer->map2, displayer->player->pos);
}
