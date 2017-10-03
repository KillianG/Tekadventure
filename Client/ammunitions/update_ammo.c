/*
** update_helmets.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:31:11 2017 Killian
** Last update Tue Oct  3 14:45:59 2017 Killian
*/

#include "tekadv.h"

void	update_ammo(t_ammo *ammo, t_displayer *displayer)
{
  ammo->pos.x = ammo->start.x + displayer->player->pos.x;
  ammo->pos.y = ammo->start.y + displayer->player->pos.y;
  sfSprite_setPosition(ammo->sprite, ammo->pos);
}

void	update_ammos(t_displayer *displayer)
{
  int	i;

  i = 0;
  while (displayer->ammo[i] != NULL)
    {
      update_ammo(displayer->ammo[i++], displayer);
    }
}
