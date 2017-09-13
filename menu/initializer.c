/*
** initializer.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Wed Sep  6 15:54:36 2017 ratch7t
** Last update Wed Sep 13 20:36:49 2017 Marc PEREZ
*/

#include "rudy.h"

sfSprite	*init_sprite_menu(char *path)
{
  sfTexture	*texture;
  sfSprite	*sprite;

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

t_displayer	*init_displayer_menu(void)
{
  t_displayer	*disp;

  if (!(disp = malloc(sizeof(t_displayer))))
    exit(84);
  disp->window = create_window_menu(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  return (disp);
}

t_sprite	*init_str_sprite(void)
{
  t_sprite	*sprit;

  if (!(sprit = malloc(sizeof(t_sprite))))
    exit (84);
  sprit->background = init_sprite_menu(BACKGROUND);
  sprit->nw_game = init_sprite_menu(NEWGAME);
  sprit->multi = init_sprite_menu(MULTI);
  sprit->option = init_sprite_menu(OPTION);
  sprit->exit = init_sprite_menu(EXIT);
  sprit->cursor = init_sprite_menu(MOUSE);
  sfSprite_setScale(sprit->background, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->nw_game, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->multi, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->option, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->exit, vector2f(1.5, 1.5));
  sfSprite_setScale(sprit->cursor, vector2f(0.15, 0.15));
  return (sprit);
}

