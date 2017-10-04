/*
** fist.c for tekadv in /root/Delivery/tekaventure/Client/weapons
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Oct  2 13:08:21 2017 root
** Last update Wed Oct  4 23:26:11 2017 Marc PEREZ
*/

#include "tekadv.h"

void		attack_fist(t_displayer *displayer)
{
  if (displayer->player->helmet == NULL)
    displayer->player->sprite = init_sprite(PLAYERT0POING,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
  else if (displayer->player->helmet->level == 1)
    displayer->player->sprite = init_sprite(PLAYERT1POING,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
  else if (displayer->player->helmet->level == 2)
    displayer->player->sprite = init_sprite(PLAYERT2POING,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
  else if (displayer->player->helmet->level == 3)
    displayer->player->sprite = init_sprite(PLAYERT3POING,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
}
