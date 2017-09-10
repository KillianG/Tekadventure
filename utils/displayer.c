/*
** displayer.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:32:50 2017 Killian
** Last update Sun Sep 10 16:58:24 2017 Killian
*/

#include "tekadv.h"

#include <time.h>

t_displayer		*init_displayer()
{
  t_displayer           *displayer;
  sfRenderWindow        *window;
  sfSprite		*sprite;
  float			x;
  float			y;

  srand(time(NULL));
  x = (rand() % 10) * -1;
  y = (rand() % 10) * -1;
  window = create_window(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = init_sprite(BACKGROUND, vector2f(x, y), vector2f(1.5, 1.5));
  if ((displayer = malloc(sizeof(t_displayer))) == NULL)
    return (NULL);
  displayer->window = window;
  displayer->map = sprite;
  displayer->player = init_player();
  displayer->player->pos.x = x;
  displayer->player->pos.y = y;
  displayer->bullet = init_sprite(BULLET, vector2f(0, 0), vector2f(0.2, 0.2));
  displayer->blue_radius = RADIUS;
  init_arrow(displayer);
  init_zone(displayer);
  init_houses(displayer);
  init_weapons(displayer);
  init_ennemies(displayer);
  init_hp(displayer);
  return (displayer);
}
