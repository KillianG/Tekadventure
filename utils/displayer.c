/*
** displayer.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:32:50 2017 Killian
** Last update Thu Sep  7 10:08:37 2017 Killian
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
  x = 0;/*(rand() % MAP_SIZEX) * -1;*/
  y = 0;/*(rand() % MAP_SIZEY) * -1;*/
  window = create_window(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = init_sprite(BACKGROUND, vector2f(x, y), vector2f(1, 1));
  if ((displayer = malloc(sizeof(t_displayer))) == NULL)
    return (NULL);
  displayer->window = window;
  displayer->map = sprite;
  displayer->player = init_player();
  displayer->player->pos.x = x;
  displayer->player->pos.y = y;
  displayer->bullet = init_sprite(BULLET, vector2f(0, 0), vector2f(0.2, 0.2));
  init_houses(displayer);
  init_weapons(displayer);
  return (displayer);
}
