/*
** angle.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:12:50 2017 Killian
** Last update Wed Aug 30 17:38:49 2017 Killian
*/

#include "tekadv.h"

float		get_angle_from_mouse(t_displayer *displayer)
{
  sfVector2i	mouse;
  float		x;
  float		y;
  float		angle;
  float		length;

  mouse = sfMouse_getPositionRenderWindow(displayer->window);
  x = mouse.x - SCREEN_WIDTH / 2;
  y = mouse.y - SCREEN_HEIGHT / 2;
  length = (sqrt(SQUARE(x) + SQUARE(y)));
  angle = acos(x / length);
  angle = TO_RAD(angle);
  if (y < 0)
    angle = 360 - angle;
  return (angle);
}
