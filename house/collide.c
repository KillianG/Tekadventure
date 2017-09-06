/*
** collide.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:01:29 2017 Killian
** Last update Wed Sep  6 13:21:48 2017 Killian
*/

#include "tekadv.h"

int		collide(t_displayer *displayer)
{
  sfFloatRect	result;
  sfFloatRect	player;
  sfFloatRect	house;
  int		curr_house;
  int		collide;

  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  collide = 0;
  curr_house = -1;
  while (displayer->houses[++curr_house] != NULL && !collide)
    {
      house = sfSprite_getGlobalBounds(displayer->houses[curr_house]->sprite);
      if (sfFloatRect_intersects(&player, &house, &result))
	collide = 1;
    }
  return (collide);
}
