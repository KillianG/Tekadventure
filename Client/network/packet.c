/*
** packet.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Oct  4 12:52:36 2017 Killian
** Last update Thu Oct  5 11:53:28 2017 Killian
*/

#include <stdbool.h>
#include "tekadv.h"

void		attack(int damages, int id)
{
  t_packet	*attack;

  if ((attack = malloc(sizeof(t_packet))) == NULL)
    return ;
  attack->id = id;
  attack->pos = vector2f(0, 0);
  attack->health = damages;
  attack->is_attack = true;
  send_data(attack);
}

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
