/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Fri Sep  8 18:54:03 2017 Marc PEREZ
*/

#include <stdio.h>
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

static int	g_socket;
static char	*g_host;
static char	*g_port;

static inline void	setnonblock(int fd)
{
  int			flags;

  flags = fcntl(fd, F_GETFL);
  flags |= O_NONBLOCK;
  fcntl(fd, F_SETFL, flags);
}

static inline void	make_socket(void)
{
  struct addrinfo	hints;
  struct addrinfo	*servinfo;
  struct addrinfo	*p;
  int			r;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  if ((r = getaddrinfo(g_host, g_port, &hints, &servinfo)) != 0)
    {
      fprintf(stderr, "Host %s at port %s DOWN\n", g_host, g_port);
      exit(1);
    }
  for (p = servinfo; p != NULL; p = p->ai_next)
    {
      if ((g_socket =
	   socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
	continue;
      if (connect(g_socket, p->ai_addr, p->ai_addrlen) == -1)
	{
	  close(g_socket);
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
  if (g_socket == 0)
    {
      make_socket();
      setnonblock(g_socket);
    }
  return (g_socket);
}

int	send_data(t_player *data)
{
  int	code;

  if ((code = send(g_socket, data, sizeof(*data), 0)) == -1)
    {
      printf("Can't send data to socket %i\n", g_socket);
      close(g_socket);
      g_socket = 0;
      socket_create();
    }
  return (code);
}

void	init_connection(char *host, char *port)
{
  g_host = host;
  g_port = port;
  socket_create();
}

t_player	*receive_data(void)
{
  t_player	temp;
  t_player	*data;

  if (read(g_socket, &temp, sizeof(temp)) > 0)
    {
      if (!(data = malloc(sizeof(t_player))))
	{
	  err(1, "Malloc failed");
	  exit(1);
	}
      memcpy(data, &temp, sizeof(*data));
      return (data);
    }
  return (NULL);
}

int		main(int argc, char **argv)
{
  t_player	*data;

  if (argc == 3)
    {
      setnonblock(0); //test
      init_connection(argv[1], argv[2]);
      while (1)
	{
	  if (!(data = malloc(sizeof(*data)))) //test
	    { //test
	      err(1, "Malloc failed"); //test
	      exit(1); //test
	    } //test
	  memset(data, 0, sizeof(*data)); //test
	  if (read(0, data->name, sizeof(data->name)) != -1) //test
	    send_data(data);
	  free(data);//test
	  data = receive_data();
	  if (data != NULL) //test
	    printf("%s", data->name); //test
	  free(data);
	}
    }
  else
    printf("USAGE: %s IP PORT\n", argv[0]);
  return (0);
}
