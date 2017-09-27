/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
<<<<<<< HEAD
** Last update Wed Sep 20 12:54:43 2017 Killian
=======
** Last update Wed Sep 20 19:34:45 2017 Marc PEREZ
>>>>>>> 52e895834fec2ea1e2b1236c91cb14df1bd2cb0c
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
      fcntl(g_socket, F_SETFL, fcntl(g_socket, F_GETFL) | O_NONBLOCK);
    }
  return (g_socket);
}

int	send_data(t_player *data)
{
  int	code;

  if ((code = send_all(g_socket, data, sizeof(*data))) == false)
    {
      printf("Can't send data to socket %i\n", g_socket);
      close(g_socket);
      g_socket = 0;
      socket_create();
    }
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
      //      exit(1);
    }
  id = ntohl(id);
  printf("ID: %i\n", id);
  return (id);
}

t_player	*receive_data(void)
{
  t_player	*data;

  if (!(data = malloc(sizeof(*data))))
    {
      err(1, "Malloc failed");
      exit(1);
    }
  if (receive_all(g_socket, data, sizeof(*data)) == true)
    {
      printf("data received = %d\n", data->id);
      return (data);
    }
  free(data);
  return (NULL);
}
