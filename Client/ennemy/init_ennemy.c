/*
** init_ennemy.c for tekadv in /home/killian/github/tekaventure/ennemy
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:11:52 2017 Killian
** Last update Thu Sep  7 14:16:08 2017 Killian
*/

#include "tekadv.h"

t_ennemy	*init_ennemy(sfVector2f pos)
{
  t_ennemy	*ennemy;

  if ((ennemy = malloc(sizeof(t_ennemy))) == NULL)
    return (NULL);
  ennemy->hp = 100;
  ennemy->pos = pos;
  ennemy->start = pos;
  ennemy->sprite = init_sprite(ENNEMY, pos, vector2f(0.8, 0.8));
  return (ennemy);
}
