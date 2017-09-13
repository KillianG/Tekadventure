/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Wed Sep 13 19:58:18 2017 Marc PEREZ
*/

#include <unistd.h>
#include <stdbool.h>

bool	send_all(int socket, void *buffer, size_t length)
{
  int	i;

  i = 0;
  while (length > 0)
    {
      write(socket, buffer, length);
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
      read(socket, buffer, length);
      if (i <= 0)
	{
	  return (false);
	}
      buffer += i;
      length -= i;
    }
  return (true);
}
