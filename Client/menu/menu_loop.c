/*
** menu_loop.c for tekadventure in /home/ratch7t/Documents/tekaventure/menu
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Thu Sep 21 13:17:22 2017 ratch7t
** Last update Sun Oct  8 15:35:03 2017 Killian
*/

#include "rudy.h"

void		left_screen_option(t_displayer *displayer, t_sprite *sprite, int id)
{
  if (sprite->mouse_pos.y <= 520 && sprite->mouse_pos.y > 485)
    {
      sfRenderWindow_drawSprite(displayer->window, sprite->nw_game, NULL);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	{
	  sfRenderWindow_close(displayer->window);
	  free(displayer);
	  free(sprite);
	  draw_game(id);
	}
    }
}

int		right_screen_option(t_displayer *displayer, t_sprite *sprite)
{
  if (sprite->mouse_pos.y <= 560 && sprite->mouse_pos.y > 520)
    {
      sfRenderWindow_drawSprite(displayer->window, sprite->option, NULL);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	displayer->zombies = 1;
    }
  else if (sprite->mouse_pos.y <= 605 && sprite->mouse_pos.y > 565)
    {
      sfRenderWindow_drawSprite(displayer->window, sprite->exit, NULL);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	return (1);
    }
  return (0);
}

int		menu_loop(t_displayer *displayer, t_sprite *sprite, int id)
{
  sfSprite	**zombies;
  int		nb;

  nb = 0;
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      sfRenderWindow_drawSprite(displayer->window, sprite->background, NULL);
      get_mouse_on_screen(displayer, sprite);
      if (sprite->mouse_pos.x >= 570 && sprite->mouse_pos.x < 650)
	{	  
	  if (right_screen_option(displayer, sprite) == 1)
	    return (-1);
	  left_screen_option(displayer, sprite, id);
	}
      sfRenderWindow_drawSprite(displayer->window, sprite->cursor, NULL);
      if (!displayer->zombies || nb == 2)
	sfRenderWindow_drawSprite(displayer->window, sprite->zomb_01, NULL);
      else
	{
	  if (nb == 0)
	    zombies = play_zombie();
	  nb = draw_animation(zombies, displayer);
	}
      if (nb == 1)
	{
	  nb = 2;
	  free(zombies);
	}
      sfRenderWindow_display(displayer->window);
      sfSleep(sfMilliseconds(20));
    }
  return (0);
}
