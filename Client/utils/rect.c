/*
** rect.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:09:49 2017 Killian
** Last update Wed Oct  4 23:20:58 2017 Marc PEREZ
*/

#include "tekadv.h"

sfFloatRect	float_rect(float top, float left,
			   float width, float height)
{
  sfFloatRect	rect;

  rect.top = top;
  rect.left = left;
  rect.width = width;
  rect.height = height;
  return (rect);
}

sfIntRect	int_rect(int top, int left, int width, int height)
{
  sfIntRect	rect;

  rect.top = top;
  rect.left = left;
  rect.width = width;
  rect.height = height;
  return (rect);
}

void	init_rect(sfIntRect *rect, sfVector2i top_left,
		  sfVector2i width_height)
{
  rect->top = top_left.x;
  rect->left = top_left.y;
  rect->width = width_height.x;
  rect->height = width_height.y;
}
