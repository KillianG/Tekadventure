
/*
** menu.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Tue Sep  5 10:13:22 2017 ratch7t
** Last update Sun Oct  8 15:25:04 2017 Killian
*/

#include "rudy.h"

sfRenderWindow		*create_window_menu(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfClose | sfResize, NULL);
  if (window == NULL)
    exit(84);
  sfRenderWindow_setMouseCursorVisible(window, sfFalse);
  sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
  return (window);
}

void		get_mouse_on_screen(t_displayer *displayer, t_sprite *sprite)
{
  sprite->mouse = sfMouse_getPositionRenderWindow(displayer->window);
  sprite->mouse_pos.x = (float)sprite->mouse.x;
  sprite->mouse_pos.y = (float)sprite->mouse.y;
  sfSprite_setPosition(sprite->cursor, sprite->mouse_pos);
}

int		menu(int id)
{
  t_displayer	*displayer;
  t_sprite	*sprite;
  
  displayer = init_displayer_menu();
  sprite = init_str_sprite();
  menu_loop(displayer, sprite, id);
  return (0);
}
