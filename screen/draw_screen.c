/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Wed Sep 13 12:56:05 2017 Killian
*/

#include "tekadv.h"

#include <unistd.h>

void		loop_network(t_displayer *displayer)
{
  int		i;

  i = 0;
  while (1)
    {
      if (i >= 50)
	{
	  reset_players(displayer);
	  i = 0;
	}
      displayer->received = receive_data();
      if (displayer->player != NULL)
	add_players(displayer);
      send_data(displayer->player);
      usleep(5000);
      i++;
    }
}

void		launch_thread(t_displayer *displayer)
{
  sfThread	*thread;

  thread = sfThread_create(loop_network, displayer);
  sfThread_launch(thread);
}

void		draw_game(int id)
{
  t_displayer	*displayer;

  displayer = init_displayer(id);
  launch_thread(displayer);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      update(displayer);
      displayer->player = update_player(displayer->player);
      get_entries(displayer);      
      sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
      draw_weapons(displayer);
      draw_houses(displayer);
      sfRenderWindow_drawSprite(displayer->window, displayer->player->sprite, NULL);
      draw_hand_weapon(displayer);
      continue_shooting(displayer);
      draw_ennemies(displayer);
      draw_players(displayer);
      draw_zone(displayer);
      draw_arrow(displayer);
      sfRenderWindow_drawText(displayer->window, displayer->hp, NULL);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
}
