/*
** list.c for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark/client/src
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:53:19 2017 Marc PEREZ
** Last update Fri Aug 25 15:21:53 2017 Marc PEREZ
*/

#include <stdlib.h>
#include "client.h"

void		append_files(t_list *list, t_info *client)
{
  t_list	*new;
  t_list	*tmp;

  tmp = list;
  if ((new = calloc(1, sizeof(t_info))) == NULL)
    exit(84);
  new->client = client;
  new->next = NULL;
  while (list != NULL)
    list = list->next;
  list = new;
  list = tmp;
}

void		pop_file(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  free(list->client);
  free(list);
  list = tmp;
}
