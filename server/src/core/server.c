/*
** main.c for tekadventure in /home/segfault/Desktop/tekaventure
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Wed Sep  6 19:09:00 2017 Marc PEREZ
** Last update Sun Sep 10 13:15:19 2017 Killian
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include <sys/queue.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include "server.h"

static struct event_base	*g_evbase;

void		buffered_on_read(struct bufferevent *bev, void *arg)
{
  t_client	*client;
  uint8_t	data[DATA_SIZE];
  size_t	n;

  while (1)
    {
      n = bufferevent_read(bev, data, sizeof(data));
      if (n <= 0)
	break;
      TAILQ_FOREACH(client, &client_tailq_head, entries)
	{
	  if (client != (t_client *)arg)
	    {
	      bufferevent_write(client->buf_ev, data, n);
	    }
	}
    }

}

void	buffered_on_error(struct bufferevent *bev, short what, void *arg)
{
  if (what & BEV_EVENT_EOF)
    {
      printf("Client disconnected.\n");
    }
  else
    {
      warn("Client socket error, disconnecting.\n");
    }
  TAILQ_REMOVE(&client_tailq_head, (t_client *)arg, entries);
  bufferevent_free(((t_client *)arg)->buf_ev);
  close(((t_client *)arg)->fd);
  free(arg);
}

void			on_accept(int fd, short ev, void *arg)
{
  struct sockaddr_in	client_addr;
  int			client_fd;
  socklen_t		client_len;
  t_client		*client;

  client_len = sizeof(client_addr);
  client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
  if (client_fd < 0)
    {
      warn("accept failed");
      return;
    }
  if (setnonblock(client_fd) < 0)
    warn("failed to set client socket non-blocking");
  if ((client = calloc(1, sizeof(*client))) == NULL)
    {
      err(1, "malloc failed");
      exit(1);
    }
  client->fd = client_fd;
  client->buf_ev = bufferevent_socket_new(g_evbase, client_fd, 0);
  bufferevent_setcb(client->buf_ev, buffered_on_read, NULL,
		    buffered_on_error, client);
  bufferevent_enable(client->buf_ev, EV_READ);
  TAILQ_INSERT_TAIL(&client_tailq_head, client, entries);
  printf("Accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));
}
