/*
** main.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:30:23 2017 Killian
** Last update Thu Oct  5 15:19:16 2017 Killian
*/

#include "tekadv.h"

int	main(int ac, char **av)
{
  printf("vrai sfkeyX = %d et nous on a : %d\n", sfKeyX, 'x' -'a');
  if (ac == 3)
    menu(init_connection(av[1], av[2]));
  return (0);
}
