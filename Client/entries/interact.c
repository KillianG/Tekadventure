/*
** interact.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 16:47:58 2017 Killian
** Last update Tue Oct  3 15:57:25 2017 Killian
*/

#include "tekadv.h"

void		interact_ammo(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	ammo;
  int		curr_w;

  curr_w = -1;
  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  while (displayer->ammo[++curr_w] != NULL)
    {
      ammo = sfSprite_getGlobalBounds(displayer->ammo[curr_w]->sprite);
      if (sfFloatRect_intersects(&player, &ammo, NULL))
	{
	  displayer->player->ammos += displayer->ammo[curr_w]->amount;
	  displayer->ammo[curr_w]->is_ground = 0;
	  sfSleep(sfMilliseconds(250));
	  break;
	}
    }
}

void		interact_equipment(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	helmet;
  int		curr_w;

  curr_w = -1;
  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  while (displayer->helmets[++curr_w] != NULL)
    {
      helmet = sfSprite_getGlobalBounds(displayer->helmets[curr_w]->sprite);
      if (sfFloatRect_intersects(&player, &helmet, NULL))
	{
	  displayer->player->hp += displayer->helmets[curr_w]->level * HP_HELMET;
	  drop_helmet(displayer);
	  displayer->helmets[curr_w]->is_head = 1;
	  displayer->player->helmet = displayer->helmets[curr_w];
	  sfSleep(sfMilliseconds(250));
	  break;
	}
    }
}

void		interact_weapon(t_displayer *displayer)
{
  sfFloatRect	player;
  sfFloatRect	weapon;
  int		curr_w;

  curr_w = -1;
  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  while (displayer->weapons[++curr_w] != NULL)
    {
      weapon = sfSprite_getGlobalBounds(displayer->weapons[curr_w]->sprite);
      if (sfFloatRect_intersects(&player, &weapon, NULL))
	{
	  drop_weapon(displayer);
	  displayer->player->has_weapon = 1;
	  displayer->player->weapon = displayer->weapons[curr_w];
	  displayer->weapons[curr_w]->is_hand = 1;
	  sfSleep(sfMilliseconds(250));
	  break;
	}
    }
}
