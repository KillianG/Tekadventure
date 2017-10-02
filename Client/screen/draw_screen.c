/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Mon Oct  2 12:17:28 2017 Killian
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
      sfThread_launch(draw);
      displayer->player->angle = get_angle_from_mouse(displayer);
      get_entries(displayer);
      move_player_mouse(displayer);
      sfThread_wait(draw);
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
  exit(1);
}
