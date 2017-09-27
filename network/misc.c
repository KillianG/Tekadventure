/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Wed Sep 27 15:30:40 2017 Marc PEREZ
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include "client.h"

bool	send_all(int socket, void *buffer, size_t length)
{
  int	i;

  i = 0;
  while (length > 0)
    {
      i = write(socket, buffer, length);
      if (i <= 0)
	{
	  return (false);
	}
      buffer += i;
      length -= i;
    }
  return (true);
}

bool	receive_all(int socket, void *buffer, size_t length)
{
  int	i;

  i = 0;
  while (length > 0)
    {
      i = read(socket, buffer, length);
      if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
	continue;
      if (i <= 0)
	{
	  return (false);
	}
      buffer += i;
      length -= i;
    }
  return (true);
}
