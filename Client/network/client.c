/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Thu Oct  5 14:39:20 2017 Killian
*/

#include <poll.h>
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
#include "tekadv.h"

static int	g_socket;
static char	*g_host;
static char	*g_port;

static inline void	make_socket(struct addrinfo *p,
				    struct addrinfo *servinfo)
{
  p = servinfo;
  while (p != NULL)
    {
      if ((g_socket =
	   socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
	{
	  p = p->ai_next;
	  continue;
	}
      if (connect(g_socket, p->ai_addr, p->ai_addrlen) == -1)
	{
	  close(g_socket);
	  p = p->ai_next;
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
}

static inline int	socket_create(void)
{
  struct addrinfo	hints;
  struct addrinfo	*servinfo;
  struct addrinfo	*p;
  int			r;

  if (g_socket == 0)
    {
      memset(&hints, 0, sizeof(hints));
      hints.ai_family = AF_UNSPEC;
      hints.ai_socktype = SOCK_STREAM;
      if ((r = getaddrinfo(g_host, g_port, &hints, &servinfo)) != 0)
	{
	  fprintf(stderr, "Host %s at port %s DOWN\n", g_host, g_port);
	  exit(1);
	}
      make_socket(p, servinfo);
    }
  return (g_socket);
}

int		send_data(t_packet *data)
{
  struct pollfd	fds;
  int		code;

  fds.fd = g_socket;
  fds.events = POLLOUT;
  poll(&fds, 1, 0);
  if (!(fds.events & POLLOUT))
    return (false);
  if ((code = send_all(g_socket, data, sizeof(*data))) == false)
    printf("Can't send data to socket %i\n", g_socket);
  return (code);
}

int	init_connection(char *host, char *port)
{
  int	id;

  g_host = host;
  g_port = port;
  if (receive_all(socket_create(), &id, sizeof(id)) == false)
    {
      printf("ERROR: Failed to receive ID\n");
      exit(1);
    }
  id = ntohl(id);
  printf("ID: %i\n", id);
  fcntl(g_socket, F_SETFL, fcntl(g_socket, F_GETFL) | O_NONBLOCK);
  return (id);
}

t_packet	*receive_data(t_player *my_player)
{
  struct pollfd	fds;
  t_packet	*data;

  fds.fd = g_socket;
  fds.events = POLLIN;
  poll(&fds, 1, 0);
  if (!(fds.events & POLLIN))
    return (NULL);
  if (!(data = malloc(sizeof(*data))))
    {
      err(1, "Malloc failed");
      exit(1);
    }
  if (receive_all(g_socket, data, sizeof(*data)) == true)
    {
      if (data->is_attack == true)
	{
	  if (data->id == my_player->id)
	    my_player->hp -= data->health;
	  free(data);
	  data = NULL;
	}
      printf("data = %d\n", data->id);
      return (data);
    }
  free(data);
  return (NULL);
}
