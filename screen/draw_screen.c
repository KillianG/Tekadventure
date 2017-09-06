/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Wed Sep  6 12:52:58 2017 Killian
*/

#include "tekadv.h"

void		draw_screen()
{
  t_displayer	*displayer;
  int		curr_house;

  displayer = init_displayer();
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      curr_house = -1;
      displayer->player = update_player(displayer->player);
      get_entries(displayer);      
      sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
      sfRenderWindow_drawSprite(displayer->window, displayer->player->sprite, NULL);
      while (displayer->houses[++curr_house] != NULL)
	{
	  sfRenderWindow_drawSprite(displayer->window,
				    displayer->houses[curr_house]->sprite, NULL);
	  update_house(displayer->houses[curr_house], displayer);
	}
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
}
