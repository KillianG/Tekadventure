/*
** update_ennemy.c for tekadv in /home/killian/github/tekaventure/ennemy
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:13:36 2017 Killian
** Last update Thu Sep  7 13:45:30 2017 Killian
*/

#include "tekadv.h"

void	update_ennemy(t_ennemy *ennemy, t_displayer *displayer)
{
  ennemy->pos.x = ennemy->start.x + displayer->player->pos.x;
  ennemy->pos.y = ennemy->start.y + displayer->player->pos.y;
  sfSprite_setPosition(ennemy->sprite, ennemy->pos);
}

void	update_ennemies(t_displayer *displayer)
{
  int	curr_e;

  curr_e = -1;
  while (displayer->ennemies[++curr_e] != NULL)
    update_ennemy(displayer->ennemies[curr_e], displayer);
}
