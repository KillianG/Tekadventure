/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Sat Sep 23 17:45:00 2017 Killian
*/

#include "tekadv.h"

#include <unistd.h>

void		launch_thread(t_displayer *displayer)
{
  sfThread	*network;
  sfThread	*update;

  network = sfThread_create(loop_network, displayer);
  update = sfThread_create(loop_update, displayer);
  sfThread_launch(update);
  sfThread_launch(network);
}

void		draw_game(int id)
{
  t_displayer	*displayer;
  sfThread	*draw;

  displayer = init_displayer(id);
  launch_thread(displayer);
  draw = sfThread_create(loop_draw, displayer);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      sfThread_launch(draw);
      displayer->player->angle = get_angle_from_mouse(displayer);
      get_entries(displayer);
      sfThread_wait(draw);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
  exit(1);
}
