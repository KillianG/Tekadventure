/*
** main.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:08:20 2017 Marc PEREZ
** Last update Sat Sep  2 14:18:38 2017 Marc PEREZ
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

t_client	g_clients[MAX_CLIENTS];

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
      socket = server(atoi(argv[1]));
      recv(socket, g_clients[0].str, MAX_STR, 0);
      printf("string = %s\n", g_clients[0].str);
    }
  else
    printf("USAGE: %s PORT\n", argv[0]);
  return (0);
}
/*
fd_set readfds;
struct timeval tv;
char buf1[256], buf2[256];

// pretend we've connected both to a server at this point
//s1 = socket(...);
//s2 = socket(...);
//connect(s1, ...)...
//connect(s2, ...)...

// clear the set ahead of time
FD_ZERO(&readfds);

// add our descriptors to the set
FD_SET(s1, &readfds);
FD_SET(s2, &readfds);

// since we got s2 second, it's the "greater", so we use that for
// the n param in select()
n = s2 + 1;

// wait until either socket has data ready to be recv()d (timeout 10.5 secs)
tv.tv_sec = 60;
tv.tv_usec = 0;


if ((rv = select(n, &readfds, NULL, NULL, &tv)) == -1)
    perror("select");
 else if (rv == 0)
     printf("Timeout occurred!  No data after %i seconds.\n", tv->tv_sec);
 else
   {

     if (FD_ISSET(s1, &readfds))
       {
	 recv(s1, buf1, sizeof buf1, 0);
       }
     if (FD_ISSET(s2, &readfds))
       {
	 recv(s2, buf2, sizeof buf2, 0);
       }
   }
*/
