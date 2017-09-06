/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Wed Sep  6 19:04:56 2017 Killian
*/

#include "tekadv.h"

void		draw_game()
{
  t_displayer	*displayer;

  displayer = init_displayer();
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      update(displayer);
      displayer->player = update_player(displayer->player);
      get_entries(displayer);      
      sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
      if (!displayer->weapon->is_hand)
	sfRenderWindow_drawSprite(displayer->window, displayer->weapon->sprite, NULL);
      draw_houses(displayer);
      sfRenderWindow_drawSprite(displayer->window, displayer->player->sprite, NULL);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
}
