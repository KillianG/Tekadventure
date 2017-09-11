/*
** players.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Sep 11 13:56:03 2017 Killian
** Last update Mon Sep 11 14:22:25 2017 Killian
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
  ids[i] = id;
  return (0);
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
