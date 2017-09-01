/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Fri Sep  1 22:53:42 2017 Marc PEREZ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

static t_list	*g_list;

int	bind_serv(struct sockaddr_in *serv, int fd, int port)
{
  serv->sin_addr.s_addr = INADDR_ANY;
  serv->sin_family = AF_INET;
  serv->sin_port = htons(port);
  if (bind(fd, (struct sockaddr *)serv, sizeof(*serv)) == -1)
    {
      write(2, "Cannot start server\n", 20);
      return (1);
    }
  return (0);
}

int			server(int port)
{
  struct sockaddr_in	serv;
  struct sockaddr	client;
  int			fd;
  int			final;
  int			socket_size;

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "Cannot create socket\n", 21);
      return (-1);
    }
  if (bind_serv(&serv, fd, port) == 1)
    return (-1);
  listen(fd, 1);
  socket_size = sizeof(struct sockaddr);
  if ((final = accept(fd, &client,
		      (socklen_t *)&socket_size)) < 0)
    {
      write(2, "Cannot accept client\n", 21);
      return (-1);
    }
  printf("ip: %s\n", inet_ntoa(((struct sockaddr_in *)&client)->sin_addr));
  return (final);
}

int	main(int argc, char **argv)
{
  int	socket;

  if (argc == 2)
    {
      if (!(g_list = malloc(sizeof(*g_list))))
	return (84);
      socket = server(atoi(argv[1]));
      char	*str;
      str = malloc(sizeof(char) * 5);
      recv(socket, str, sizeof(char) * 5, 0);
      printf("string = %s\n", str);
    }
  else
    printf("USAGE: %s PORT\n", argv[0]);
  return (0);
}
