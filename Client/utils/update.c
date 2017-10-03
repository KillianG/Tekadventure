/*
** update.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:35:58 2017 Killian
** Last update Tue Oct  3 15:10:16 2017 Killian
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
  update_ennemies(displayer);
  update_zone(displayer);
  update_hp(displayer);
  update_ammo_text(displayer);
  update_helmets(displayer);
  update_ammos(displayer);
  if (displayer->player->hp <= 0)
    {
      printf("T'as perdu grosse m*r*e\n");
      exit(0);
    }
}