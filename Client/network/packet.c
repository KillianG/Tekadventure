/*
** packet.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Oct  4 12:52:36 2017 Killian
** Last update Wed Oct  4 12:56:20 2017 Killian
*/

#include "tekadv.h"

t_packet	*new_packet(t_player *player)
{
  t_packet	*packet;

  if ((packet = malloc(sizeof(t_packet))) == NULL)
    return (NULL);
  packet->id = player->id;
  packet->pos = player->pos;
  packet->health = player->hp;
  return (packet);
}
