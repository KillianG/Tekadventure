/*
** initializer.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Wed Sep  6 15:54:36 2017 ratch7t
** Last update Wed Sep  6 16:54:47 2017 ratch7t
*/

#include "rudy.h"

sfSprite                *init_sprite(char *path)
{
  sfTexture             *texture;
  sfSprite              *sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

t_displayer     *init_displayer()
{
  t_displayer   *disp;

  if (!(disp = malloc(sizeof(t_displayer))))
    exit (84);
  disp->window = create_window(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  return (disp);
}

t_sprite        *init_str_sprite()
{
  t_sprite      *sprit;

  if (!(sprit = malloc(sizeof(t_sprite))))
    exit (84);
  sprit->background = init_sprite(BACKGROUND);
  sprit->nw_game = init_sprite(NEWGAME);
  sprit->multi = init_sprite(MULTI);
  sprit->option = init_sprite(OPTION);
  sprit->exit = init_sprite(EXIT);
  sprit->cursor = init_sprite(MOUSE);
  sfSprite_setScale(sprit->background, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->nw_game, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->multi, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->option, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->exit, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->cursor, vector2f(0.15, 0.15));
  return (sprit);
}

