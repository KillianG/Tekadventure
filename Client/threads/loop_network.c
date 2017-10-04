/*
** loop_network.c for tekadv in /home/killian/github/tekaventure/threads
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep 20 12:44:22 2017 Killian
** Last update Wed Oct  4 23:41:10 2017 Marc PEREZ
*/

#include <unistd.h>
#include "tekadv.h"

void		loop_network(void *param)
{
  t_displayer	*displayer;
  int		i;

  displayer = param;
  i = 0;
  if (i >= 50)
    {
      //      reset_players(displayer);
      i = 0;
    }
  displayer->received = receive_data();
  if (displayer->player != NULL)
    {
      add_players(displayer);
    }
  send_data(new_packet(displayer->player));
  ++i;
}
