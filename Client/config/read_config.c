/*
** read_config.c for tekadv in /root/Delivery/tekaventure/Client/config
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Fri Oct  6 15:33:52 2017 root
** Last update Fri Oct  6 17:41:02 2017 root
*/

#include <stdio.h>
#include "tekadv.h"

int	my_strstr(char *buffer, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (buffer[i])
    {
      while (buffer[i] == str[j])
	{
	  ++i;
	  ++j;
	}
      if (str[j] == '\0' && ((buffer[i + 1] >= 'a' && buffer[i + 1] <= 'z')
			  || (buffer[i + 1] >= 'A' && buffer[i + 1] <= 'Z')))
	return (i + 1);
      j = 0;
      ++i;
    }
  return (-1);
}

char	caps(char c)
{
  if (c >= 'a' && c <= 'z')
    c -= 32;
  return (c);
}

void	default_config(t_displayer *displayer)
{
  displayer->config->up = sfKeyZ;
  displayer->config->left = sfKeyQ;
  displayer->config->down = sfKeyS;
  displayer->config->right = sfKeyD;
  displayer->config->take = sfKeyE;
  displayer->config->drop = sfKeyA;
}

void		config_key(t_displayer *displayer, char *buffer)
{
  if (my_strstr(buffer, "UP") != -1 && my_strstr(buffer, "LEFT") != -1 &&
      my_strstr(buffer, "DOWN") != -1 && my_strstr(buffer, "RIGHT") != -1 &&
      my_strstr(buffer, "TAKE") != -1 && my_strstr(buffer, "DROP") != -1)
    {
      displayer->config->up = caps(buffer[my_strstr(buffer, "UP")]) - 65;
      displayer->config->left = caps(buffer[my_strstr(buffer, "LEFT")]) - 65;
      displayer->config->down = caps(buffer[my_strstr(buffer, "DOWN")]) - 65;
      displayer->config->right = caps(buffer[my_strstr(buffer, "RIGHT")]) - 65;
      displayer->config->take = caps(buffer[my_strstr(buffer, "TAKE")]) - 65;
      displayer->config->drop = caps(buffer[my_strstr(buffer, "DROP")]) - 65;
    }
  else
    default_config(displayer);
}

void		read_config(t_displayer *displayer)
{
  t_config	*config;
  char		*buffer;

  if ((config = malloc(sizeof(config))) == NULL)
    return ;
  displayer->config = config;
  buffer = read_file(CONFIG);
  config_key(displayer, buffer);
}
