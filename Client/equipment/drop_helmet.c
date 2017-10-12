/*
** drop_helmet.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 15:49:30 2017 Killian
** Last update Mon Oct  2 16:38:42 2017 Killian
*/

#include "tekadv.h"

void		drop_helmet(t_displayer *displayer)
{
  sfVector2f	pos;

  pos.x = (displayer->player->pos.x * -1) + SCREEN_WIDTH/2;
  pos.y = (displayer->player->pos.y * -1) + SCREEN_HEIGHT/2;
  if (displayer->player->helmet != NULL)
    {
      displayer->player->hp -= displayer->player->helmet->level * HP_HELMET;
      displayer->player->helmet->is_head = 0;
      displayer->player->helmet->start = pos;
    }
}
