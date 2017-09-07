/*
** GNL.c for GNL in /home/segfault/Delivery/Cleanup/matchstick/GNL
** 
** Made by Marc
** Login   <marc.perez@epitech.eu>
** 
** Started on  Sun Jul  2 23:05:55 2017 Marc
** Last update Mon Jul  3 11:12:30 2017 Marc
*/

#include	"GNL.h"

static t_list	*add_in_list(t_list *list, char c)
{
  t_list	*new_element;
  t_list	*tmp;

  if (!(new_element = malloc(sizeof(t_list))))
    return (NULL);
  new_element->c = c;
  new_element->next = NULL;
  if (!list)
    return (new_element);
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new_element;
  return (list);
}

static int	check_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if ((tmp->c == '\n' || tmp->c == '\0'))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

static int	str_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp)
    {
      if ((tmp->c == '\n' || tmp->c == '\0'))
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (i);
}

static char	*list_to_str(t_list **list)
{
  t_list	*ptr;
  char		*str;
  int		i;

  i = 0;
  if (!(*list))
    return (NULL);
  if (!(str = malloc(sizeof(char) * (str_size(*list) + 1))))
    return (NULL);
  while (((*list) && ((*list)->c != '\n') && (*list)->c))
    {
      ptr = (*list);
      str[i++] = (*list)->c;
      (*list) = (*list)->next;
      free(ptr);
    }
  str[i] = '\0';
  if (*list)
    {
      ptr = (*list);
      (*list) = (*list)->next;
      free(ptr);
    }
  return (str);
}

char		*get_next_line(const int fd)
{
  static t_list	*list;
  char		buffer[BUFF_SIZE];
  int		val;
  int		i;

  i = 0;
  while (i < BUFF_SIZE)
    buffer[i++] = 0;
  if ((val = read(fd, buffer, BUFF_SIZE)) < 0)
    return (NULL);
  if (!(i = 0) && (val == 0))
    return (list_to_str(&list));
  while (i < val)
    if (!(list = add_in_list(list, buffer[i++])))
      return (NULL);
  if (check_list(list))
    return (list_to_str(&list));
  return (get_next_line(fd));
}
