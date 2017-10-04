/*
** my_itoa.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:57:30 2017 Killian
** Last update Wed Oct  4 23:19:52 2017 Marc PEREZ
*/

#include "tekadv.h"

char		*my_itoa(int nb)
{
  int		len;
  char		*str;
  int		tmp;

  tmp = nb;
  len = 0;
  if (nb == 0)
    return ("0");
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if (!(str = malloc(sizeof(*str) * (len + 1))))
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
