/*
** update_helmets.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:31:11 2017 Killian
** Last update Mon Oct  2 14:49:05 2017 Killian
*/

#include "tekadv.h"

void	update_helmet(t_helmet *helmet, t_displayer *displayer)
{
  helmet->pos.x = helmet->start.x + displayer->player->pos.x;
  helmet->pos.y = helmet->start.y + displayer->player->pos.y;
  sfSprite_setPosition(helmet->sprite, helmet->pos);
}

void	update_helmets(t_displayer *displayer)
{
  int	i;

  i = 0;
  while (displayer->helmets[i] != NULL)
    {
      update_helmet(displayer->helmets[i++], displayer);
    }
}
