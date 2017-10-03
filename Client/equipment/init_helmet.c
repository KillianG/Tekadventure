/*
** helmet.c for tekadv in /home/killian/github/tekaventure/Client/equipment
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 14:13:43 2017 Killian
** Last update Tue Oct  3 13:48:14 2017 Killian
*/

#include "tekadv.h"

t_helmet	*init_helmet(sfVector2f pos, int lvl)
{
  t_helmet	*helmet;

  if ((helmet = malloc(sizeof(t_helmet))) == NULL)
    return (NULL);
  helmet->pos = pos;
  helmet->start = pos;
  if (lvl == 1)
    helmet->sprite = init_sprite(HELMET1, pos, vector2f(0.1, 0.1));
  else if (lvl == 2)
    helmet->sprite = init_sprite(HELMET2, pos, vector2f(0.1, 0.1));
  else
    helmet->sprite = init_sprite(HELMET3, pos, vector2f(0.1, 0.1));
  helmet->level = lvl;
  helmet->is_head = 0;
  return (helmet);
}
