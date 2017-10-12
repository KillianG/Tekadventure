/*
** move.c for tekadv in /home/killian/github/tekaventure/Client/mandatory
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 12:04:48 2017 Killian
** Last update Sun Oct  8 19:02:33 2017 Killian
*/

#include "tekadv.h"

void	move_player_mouse(t_displayer *displayer)
{
  displayer->player->pos = move_forward(displayer->player->pos,
    displayer->player->angle,
    SPEED * -1);
  if (collide(displayer))
    displayer->player->pos = move_forward(displayer->player->pos,
    displayer->player->angle,
    SPEED);
  update_map(displayer);
}
