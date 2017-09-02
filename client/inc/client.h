/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Sat Sep  2 14:52:35 2017 Marc PEREZ
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# define MAX_STR	1024

typedef struct	s_client
{
  int		socket;
  char		str[MAX_STR];
}		t_client;

extern t_client	g_clients[FD_SETSIZE];

#endif /* !CLIENT_H_ */
