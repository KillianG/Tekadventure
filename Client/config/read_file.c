/*
** read_file.c for tekadv in /root/Delivery/tekaventure/Client/config
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Fri Oct  6 23:37:10 2017 root
** Last update Fri Oct  6 23:44:22 2017 root
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tekadv.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void	create_config(char *str)
{
  int	fd;

  fd = open(str, O_CREAT);
  close(fd);
  fd = open(str, O_WRONLY);
  write(fd, LINE0, my_strlen(LINE0));
  write(fd, LINE1, my_strlen(LINE1));
  write(fd, LINE2, my_strlen(LINE2));
  write(fd, LINE3, my_strlen(LINE3));
  write(fd, LINE4, my_strlen(LINE4));
  write(fd, LINE5, my_strlen(LINE5));
  write(fd, LINE6, my_strlen(LINE6));
  close(fd);
}

char		*read_file(char *str)
{
  struct stat	size;
  char		*map;
  int		fd;

  if ((stat(str, &size)) == -1)
    {
      create_config(str);
      stat(str, &size);
    }
  if ((map = malloc(sizeof(char) * (size.st_size + 1))) == NULL)
    return (NULL);
  if ((fd = open(str, O_RDONLY)) == -1)
    return (NULL);
  if ((read(fd, map, size.st_size)) == -1)
    return (NULL);
  close(fd);
  map[size.st_size] = '\0';
  return (map);
}
