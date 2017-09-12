/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Mon Sep 11 14:03:31 2017 Marc PEREZ
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "tekadv.h"

/*
** Place this at the beginning of the program
** Return the ID
*/

int		init_connection(char *host, char *port);

/*
** Receives 1 malloc'd structure (or NULL)
*/

t_player	*receive_data(void);

/*
** Sends 1 structure to everyone but the sender
*/

int		send_data(t_player *data);

#endif /* !CLIENT_H_ */
