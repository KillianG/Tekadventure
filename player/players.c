/*
** players.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Sep 11 13:56:03 2017 Killian
** Last update Mon Sep 11 14:31:30 2017 Killian
*/

#include "tekadv.h"

int		is_in_ids(int id)
{
  static int	ids[50];
  int		i;

  i = 0;
  memset(ids, -1, 50);
  while (i++ <= 50)
    {
      if (ids[i] == id)
	return (1);
    }
  printf("id %d is connected\n", id);
  ids[i] = id;
  return (0);
}

void		draw_players(t_displayer *displayer)
{
  sfSprite	*sprite;
  int		i;

  sprite = init_sprite(TEST, vector2f(0, 0), vector2f(1, 1));
  i = 0;
  while (displayer->players[i] != NULL)
    {
      sfSprite_setPosition(sprite,
			   vector2f((displayer->players[i]->pos.x * -1) +
				    SCREEN_WIDTH/2 +
				    displayer->player->pos.x,
				    (displayer->players[i]->pos.y * -1) +
				    SCREEN_HEIGHT/2 +
				    displayer->player->pos.y));
      sfRenderWindow_drawSprite(displayer->window, sprite, NULL);
      i++;
    }
}

void		add_players(t_displayer *displayer)
{
  static int	id = 0;

  if (displayer->received != NULL && !is_in_ids(displayer->received->id))
    {
      displayer->players[id++] = displayer->received;
      displayer->players[id] = NULL;
    }
}

void		init_players(t_displayer *displayer)
{
  t_player	**players;

  players = malloc(sizeof(t_player *) * 50);
  players[0] = NULL;
  displayer->players = players;
}
