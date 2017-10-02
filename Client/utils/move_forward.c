/*
** move_forward.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:59:31 2017 Killian
** Last update Wed Sep  6 21:00:05 2017 Killian
*/

#include "tekadv.h"

sfVector2f      move_forward(sfVector2f pos, float angle, float distance)
{
  sfVector2f    a;

  angle = TO_RAD(angle);
  a.x = (distance * cos(angle)) + pos.x;
  a.y = (distance * sin(angle)) + pos.y;
  return (a);
}
