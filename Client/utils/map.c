/*
** map.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:07:08 2017 Killian
** Last update Wed Aug 30 18:07:54 2017 Killian
*/

#include "tekadv.h"

void	update_map(t_displayer *displayer)
{
  sfSprite_setPosition(displayer->map, displayer->player->pos);
}
