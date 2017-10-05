/*
** loop_network.c for tekadv in /home/killian/github/tekaventure/threads
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep 20 12:44:22 2017 Killian
** Last update Thu Oct  5 13:55:37 2017 Killian
*/

#include <unistd.h>
#include "tekadv.h"

void		loop_network(void *param)
{
  t_displayer	*displayer;

  displayer = param;
  while (1)
    {
      displayer->received = receive_data(displayer->player);
      if (displayer->player != NULL)
	{
	  add_players(displayer);
	}
      send_data(new_packet(displayer->player));
    }
}
