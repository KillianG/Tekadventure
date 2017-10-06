/*
** menu.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Tue Sep  5 10:13:22 2017 ratch7t
** Last update Fri Oct  6 17:12:37 2017 root
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

void		menu_loop(t_displayer *displayer, t_sprite *sprite, int id)
{
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      sfRenderWindow_drawSprite(displayer->window, sprite->background, NULL);
      get_mouse_on_screen(displayer, sprite);
      if (sprite->mouse_pos.x <= 600 && sprite->mouse_pos.x > 50)
	{
          if (sprite->mouse_pos.y <= 140 && sprite->mouse_pos.y > 60)
	    {
	      sfRenderWindow_drawSprite(displayer->window, sprite->nw_game, NULL);
	      if (sfMouse_isButtonPressed(sfMouseLeft))
		{
		  sfRenderWindow_close(displayer->window);
		  draw_game(id);
		}
	    }
          else if (sprite->mouse_pos.y <= 270 && sprite->mouse_pos.y > 180)
            sfRenderWindow_drawSprite(displayer->window, sprite->multi, NULL);
          else if (sprite->mouse_pos.y <= 370 && sprite->mouse_pos.y > 280)
            sfRenderWindow_drawSprite(displayer->window, sprite->option, NULL);
          else if (sprite->mouse_pos.y <= 490 && sprite->mouse_pos.y > 390)
            {
              sfRenderWindow_drawSprite(displayer->window, sprite->exit, NULL);
              if (sfMouse_isButtonPressed(sfMouseLeft))
		break;
            }
        }
      sfRenderWindow_drawSprite(displayer->window, sprite->cursor, NULL);
      sfRenderWindow_display(displayer->window);
    }
}

int		menu(int id)
{
  t_displayer	*displayer;
  t_sprite	*sprite;

  displayer = init_displayer_menu();
  sprite = init_str_sprite();
  menu_loop(displayer, sprite, id);
  free(displayer);
  free(sprite);
  return (0);
}
