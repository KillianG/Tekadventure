/*
** socket.c for tekadventure in /home/segfault/Desktop/tekaventure
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Wed Sep  6 19:09:13 2017 Marc PEREZ
** Last update Fri Sep  8 16:18:21 2017 Marc PEREZ
*/

#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "server.h"

int	setnonblock(int fd)
{
  int	flags;

  flags = fcntl(fd, F_GETFL);
  if (flags < 0)
    return (flags);
  flags |= O_NONBLOCK;
  if (fcntl(fd, F_SETFL, flags) < 0)
    return (-1);
  return (0);
}

void			init_socket(char *port, int *listen_fd)
{
  struct sockaddr_in	listen_addr;
  int			reuseaddr_on;

  *listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (*listen_fd == -1)
    err(1, "listen failed");
  memset(&listen_addr, 0, sizeof(listen_addr));
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_addr.s_addr = INADDR_ANY;
  listen_addr.sin_port = htons(atoi(port));
  if (bind(*listen_fd, (struct sockaddr *)&listen_addr,
	   sizeof(listen_addr)) == -1)
    err(1, "bind failed");
  if (listen(*listen_fd, 5) == -1)
    err(1, "listen failed");
  reuseaddr_on = 1;
  setsockopt(*listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_on,
	     sizeof(reuseaddr_on));
}
