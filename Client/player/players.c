/*
** players.c for tekadv in /home/killian/github/tekaventure/player
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Sep 11 13:56:03 2017 Killian
** Last update Thu Sep 28 15:24:56 2017 Killian
*/

#include "tekadv.h"

void		add_players(t_displayer *displayer)
{
  displayer->players[displayer->player->id] = displayer->player;
  if (displayer->received != NULL)
    {
      displayer->players[displayer->received->id] = displayer->received;
    }
}

void		reset_players(t_displayer *displayer)
{
  int		i;

  i = 0;
  while (i < 50)
    {
      displayer->players[i] = NULL;
      i++;
    }
}

void		draw_players(t_displayer *displayer)
{
  sfSprite	*sprite;
  
  sprite = init_sprite(TEST, vector2f(0, 0), vector2f(1, 1));
  if (displayer->received != NULL)
    {
      printf("oui\n");
      sfSprite_setPosition(sprite,
			   vector2f((displayer->received->pos.x * -1) +
				    SCREEN_WIDTH/2 +
				    displayer->player->pos.x,
				    (displayer->received->pos.y * -1) +
				    SCREEN_HEIGHT/2 +
				    displayer->player->pos.y));
      sfRenderWindow_drawSprite(displayer->window, sprite, NULL);
    }
}

void		init_players(t_displayer *displayer)
{
  t_player	**players;
  int		i;

  i = 0;
  players = malloc(sizeof(t_player *) * 50);
  players[0] = NULL;
  while (i < 50)
    {
      players[i] = NULL;
      i++;
    }
  displayer->players = players;
}
