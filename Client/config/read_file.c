/*
** map_len.c for bsq in /root/Delivery/CProg_Elem/CPE_2016_BSQ
**
** Made by root
** Login   <kentin.pratelli@epitech.eu>
**
** Started on  Wed May  3 00:29:01 2017 root
** Last update Fri Oct  6 16:12:44 2017 root
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tekadv.h"

char		*read_file(char *str)
{
  struct stat	size;
  char		*map;

  if ((stat(str, &size)) == -1)
    return (NULL);
  if ((map = malloc(sizeof(char) * (size.st_size + 1))) == NULL)
    return (NULL);
  if ((read(open(str, O_RDONLY), map, size.st_size)) == -1)
    return (NULL);
  close(open(str, O_RDONLY));
  map[size.st_size] = '\0';
  return (map);
}
