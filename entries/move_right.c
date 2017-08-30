/*
** move_right.c for tekadv in /home/killian/github/tekaventure/entries
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:04:35 2017 Killian
** Last update Wed Aug 30 18:28:48 2017 Killian
*/

#include "tekadv.h"

void		move_right(t_displayer *displayer)
{
  static int	x = 0;

  x++;
  if (x == 200 && !(x = 0))
    displayer->player->sprite_pos++;
  if (displayer->player->sprite_pos > 3)
    displayer->player->sprite_pos = 0;
  displayer->player->pos.x -= SPEED;
  displayer->player->hitbox = int_rect(64 * 2,
				       displayer->player->sprite_pos * 64,
				       64, 64);
  update_map(displayer);
  update_player(displayer->player);
}
