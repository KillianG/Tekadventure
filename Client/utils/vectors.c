/*
** vectors.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:06:14 2017 Killian
** Last update Wed Aug 30 17:39:23 2017 Killian
*/

#include "tekadv.h"

sfVector2i	vector2i(int x, int y)
{
  sfVector2i	v;

  v.x = x;
  v.y = y;
  return (v);
}

sfVector2f	vector2f(float x, float y)
{
  sfVector2f	v;

  v.x = x;
  v.y = y;
  return (v);
}
