/*
** players.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Sep 11 13:56:03 2017 Killian
** Last update Sat Oct  7 18:39:58 2017 Killian
*/

#include "tekadv.h"

void		add_players(t_displayer *displayer)
{
  displayer->players[displayer->player->id] = new_packet(displayer->player);
  if (displayer->received != NULL)
    {
      displayer->players[displayer->received->id] = displayer->received;
    }
}

void		draw_players(t_displayer *displayer)
{
  sfSprite	*sprite;
  int		i;

  i = 0;
  while (i < NB_PLAYERS)
    {
      if (displayer->players[i] != NULL && i != displayer->player->id)
	{
	  sprite = init_sprite(TEST, vector2f(0, 0), vector2f(1, 1));
	  sfSprite_setPosition(sprite,
			       vector2f((displayer->players[i]->pos.x * -1) +
					SCREEN_WIDTH/2 +
					displayer->player->pos.x,
					(displayer->players[i]->pos.y * -1) +
					SCREEN_HEIGHT/2 +
					displayer->player->pos.y));
	  sfRenderWindow_drawSprite(displayer->window, sprite, NULL);
	}
      i++;
    }
}

void		init_players(t_displayer *displayer)
{
  t_packet	**players;
  int		i;

  i = 0;
  if (!(players = malloc(sizeof(t_player *) * 50)))
    exit(84);
  players[0] = NULL;
  while (i < 50)
    {
      players[i] = NULL;
      i++;
    }
  displayer->players = players;
}
