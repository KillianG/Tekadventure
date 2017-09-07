/*
** update.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:35:58 2017 Killian
** Last update Thu Sep  7 10:07:35 2017 Killian
*/

#include "tekadv.h"

void	update(t_displayer *displayer)
{
  int	curr_house;

  curr_house = -1;
  while (displayer->houses[++curr_house] != NULL)
    update_house(displayer->houses[curr_house], displayer);
  update_player(displayer->player);
  update_weapons(displayer);
}
