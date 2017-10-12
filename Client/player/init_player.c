/*
** init_player.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 17:59:04 2017 Killian
** Last update Thu Oct  5 00:34:38 2017 Marc PEREZ
*/

#include <stdbool.h>
#include "tekadv.h"

t_player	*init_player(int id)
{
  t_player	*player;

  player = malloc(sizeof(t_player));
  player = memset(player, 0, sizeof(t_player));
  player->sprite = init_sprite(PLAYER,
                               vector2f(SCREEN_WIDTH/2 - 25,
					SCREEN_HEIGHT/2 - 25),
                               vector2f(1, 1));
  printf("my_id : %d\n", id);
  player->id = 1;
  player->hp = 100;
  player->pos.x = 0;
  player->pos.y = 0;
  player->has_weapon = 0;
  player->shoot = 0;
  player->weapon = NULL;
  player->hitbox = int_rect(0, 0, 64, 64);
  player->ammos = 0;
  player->is_attack = false;
  return (player);
}
