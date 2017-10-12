/*
** update_player.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 17:53:53 2017 Killian
** Last update Wed Aug 30 18:04:04 2017 Killian
*/

#include "tekadv.h"

t_player	*update_player(t_player *player)
{
  sfSprite_setTextureRect(player->sprite, player->hitbox);
  return (player);
}
