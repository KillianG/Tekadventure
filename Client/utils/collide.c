/*
** collide.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:01:29 2017 Killian
** Last update Sun Oct  8 16:11:26 2017 Killian
*/

#include "tekadv.h"

int			is_transparent(t_displayer *displayer)
{
  static sfImage	*image;
  sfColor		color;
  static int		a = 0;
  unsigned int		x;
  unsigned int		y;

  x = (((displayer->player->pos.x) * -1)/ 1.5) + SCREEN_WIDTH/2 - 175;
  y = (((displayer->player->pos.y) * -1)/ 1.5) + SCREEN_HEIGHT/2 - 100;
  if (!a)
    {
      image = sfTexture_copyToImage(sfSprite_getTexture(displayer->map1));
      a = !a;
    }
  color = sfImage_getPixel(image, x, y);;
  if (color.a == 0)
    return (1);
  return (0);
}

int		collide(t_displayer *displayer)
{
  if (!is_transparent(displayer))
    return (1);
  return (0);
}
