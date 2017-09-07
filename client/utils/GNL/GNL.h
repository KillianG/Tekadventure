/*
** GNL.h for GNL in /home/segfault/Delivery/Cleanup/matchstick/GNL
** 
** Made by Marc
** Login   <marc.perez@epitech.eu>
** 
** Started on  Sun Jul  2 22:59:06 2017 Marc
** Last update Mon Jul  3 13:40:23 2017 Marc
*/

#ifndef GNL_H_
# define GNL_H_

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1

typedef	struct	s_list t_list;

struct		s_list
{
  char		c;
  t_list	*next;
};

char	*get_next_line(const int);

#endif /* !GNL_H_ */
