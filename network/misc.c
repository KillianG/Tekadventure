/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Wed Sep 13 19:25:01 2017 Marc PEREZ
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <err.h>
#include "client.h"
#include "game.h"
#include "tekadv.h"

bool	send_all(int socket, void *buffer, size_t length)
{
  int	i;

  i = 0;
  while (length > 0)
    {
      write(socket, buffer, length);
      if (i < 1)
	{
	  return (false);
	}
      buffer += i;
      length -= i;
    }
  return (true);
}
