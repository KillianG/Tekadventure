/*
** displayer.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:32:50 2017 Killian
** Last update Wed Aug 30 18:12:12 2017 Killian
*/

#include "tekadv.h"

#include <time.h>

t_displayer	*init_displayer()
{
  t_displayer           *displayer;
  sfRenderWindow        *window;
  sfSprite		*sprite;
  float			x;
  float			y;

  srand(time(NULL));
  x = (rand() % MAP_SIZEX) * -1;
  y = (rand() % MAP_SIZEY) * -1;
  window = create_window(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = init_sprite(BACKGROUND, vector2f(x, y), vector2f(1, 1));
  displayer = malloc(sizeof(t_displayer));
  displayer->window = window;
  displayer->map = sprite;
  displayer->player = init_player();
  displayer->player->pos.x = x;
  displayer->player->pos.y = y;
  return (displayer);
}
