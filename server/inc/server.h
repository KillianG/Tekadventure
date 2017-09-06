/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Wed Sep  6 22:10:32 2017 Marc PEREZ
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# define SERVER_PORT			12345
# define DATA_SIZE			8192

# define ERR_EXIT(fd, str, code)	{ err(fd, str); exit(code); }

typedef struct		s_client
{
  TAILQ_ENTRY(s_client)	entries;
  struct bufferevent	*buf_ev;
  int			fd;
}			t_client;

TAILQ_HEAD(, s_client)	client_tailq_head;

int	setnonblock(int fd);
void	init_socket(int *listen_fd);

#endif /* !CLIENT_H_ */
