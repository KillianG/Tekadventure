/*
** windows.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:07:46 2017 Killian
** Last update Wed Aug 30 16:08:05 2017 Killian
*/

#include "tekadv.h"

sfRenderWindow          *create_window(char * name, int width, int height)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  sfRenderWindow_setMouseCursorVisible(window, sfFalse);
  if (window == NULL)
    exit(84);
  return (window);
}
