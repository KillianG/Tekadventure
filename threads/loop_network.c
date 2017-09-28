/*
** loop_network.c for tekadv in /home/killian/github/tekaventure/threads
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep 20 12:44:22 2017 Killian
** Last update Thu Sep 28 15:28:09 2017 Killian
*/

#include "tekadv.h"
#include <unistd.h>

void            *loop_network(t_displayer *displayer)
{
  int           i;
  
  i = 0;
  while (1)
    {
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
      send_data(displayer->player);
      usleep(500);
      i++;
    }
}
