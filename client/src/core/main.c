/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Fri Sep  1 22:54:01 2017 Marc PEREZ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include "client.h"

static t_list	*g_list;

int			make_socket(char *host, char *port)
{
  struct addrinfo	hints;
  struct addrinfo	*servinfo;
  struct addrinfo	*p;
  int			sock;
  int			r;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  if ((r = getaddrinfo(host, port, &hints, &servinfo)) != 0)
    {
      fprintf(stderr, "Host %s at port %s DOWN\n", host, port);
      exit(1);
    }
  for (p = servinfo; p != NULL; p = p->ai_next)
    {
      if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
	  continue;
      if (connect(sock, p->ai_addr, p->ai_addrlen) == -1)
	{
	  close(sock);
	  continue;
	}
      break;
    }
  if (p == NULL)
    {
      if (servinfo)
	freeaddrinfo(servinfo);
      exit(0);
    }
  if (servinfo)
    freeaddrinfo(servinfo);
  return (sock);
}

void		attack(char *host, char *port)
{
  static int	socket;

  if (socket == 0)
    {
      socket = make_socket(host, port);
    }
  //test
  char	*str;
  str = malloc(sizeof(char) * 5);
  strcpy(str, "test");
//test end
  if (send(socket, str, sizeof(char) * 5, 0) <= 0)
    {
      close(socket);
      socket = 0;
    }
}

int	main(int argc, char **argv)
{
  signal(SIGPIPE, SIG_IGN);
  if (argc == 3)
    {//test
      if (!(g_list = malloc(sizeof(*g_list))))
	return (84);
      //test end
      attack(argv[1], argv[2]);
    }
  else
    printf("USAGE: %s IP PORT\n", argv[0]);
  return (0);
}
