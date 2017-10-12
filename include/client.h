/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Thu Oct  5 00:17:38 2017 Marc PEREZ
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdbool.h>
# include "tekadv.h"

/*
** Place this at the beginning of the program
** Return the ID
*/

int		init_connection(char *host, char *port);

/*
** Receives 1 malloc'd structure (or NULL) and removes health in case of a hit
*/

t_packet	*receive_data(t_player *my_player);

/*
** Sends 1 structure to everyone but the sender
*/

int		send_data(t_packet *data);

bool		send_all(int socket, void *buffer, size_t length);
bool		receive_all(int socket, void *buffer, size_t length);

t_packet	*new_packet(t_player *player);

#endif /* !CLIENT_H_ */
