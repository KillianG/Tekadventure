/*
** packet.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Oct  4 12:52:36 2017 Killian
** Last update Thu Oct  5 00:24:22 2017 Marc PEREZ
*/

#include <stdbool.h>
#include "tekadv.h"

t_packet	*new_packet(t_player *player)
{
  t_packet	*packet;

  if ((packet = malloc(sizeof(t_packet))) == NULL)
    return (NULL);
  packet->id = (player->is_attack == true) ?
    player->attack_id : player->id;
  packet->pos = player->pos;
  packet->health = (player->is_attack == true) ?
    player->attack_damage : player->hp;
  packet->is_attack = player->is_attack;
  return (packet);
}
