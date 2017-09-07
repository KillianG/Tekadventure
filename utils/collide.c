/*
** collide.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:01:29 2017 Killian
** Last update Thu Sep  7 15:26:23 2017 Killian
*/

#include "tekadv.h"

int		collide(t_displayer *displayer)
{
  sfFloatRect	result;
  sfFloatRect	player;
  sfFloatRect	hitbox;
  int		cpt;
  int		collide;

  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  collide = 0;
  cpt = -1;
  while (displayer->houses[++cpt] != NULL && !collide)
    {
      hitbox = sfSprite_getGlobalBounds(displayer->houses[cpt]->sprite);
      if (sfFloatRect_intersects(&player, &hitbox, &result))
	collide = 1;
    }
  cpt = -1;
  while (displayer->ennemies[++cpt] != NULL && !collide)
    {
      hitbox = sfSprite_getGlobalBounds(displayer->ennemies[cpt]->sprite);
      if (sfFloatRect_intersects(&player, &hitbox, &result) &&
	  displayer->ennemies[cpt]->hp > 0)
	{
	  displayer->player->hp -= 0.01;
	  collide = 1;
	}
    }
  return (collide);
}
