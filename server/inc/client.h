/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Fri Aug 25 15:14:22 2017 Marc PEREZ
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct	s_info
{
  char		*str;
}		t_info;

typedef struct	s_list
{
  struct s_list	*next;
  t_info	*client;
}		t_list;

#endif /* !CLIENT_H_ */
