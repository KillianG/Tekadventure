/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
<<<<<<< HEAD
** Last update Sat Sep 23 17:45:00 2017 Killian
=======
** Last update Wed Sep 20 17:41:53 2017 Marc PEREZ
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
*/

#include <unistd.h>
#include "tekadv.h"

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
<<<<<<< HEAD
      sfThread_launch(draw);
      displayer->player->angle = get_angle_from_mouse(displayer);
      get_entries(displayer);
      sfThread_wait(draw);
=======
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
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
  exit(1);
}
