/*
** main.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:30:23 2017 Killian
** Last update Tue Oct  3 14:03:52 2017 Killian
*/

#include "tekadv.h"

int	main(int ac, char **av)
{
  if (ac == 3)
    menu(init_connection(av[1], av[2]));
  return (0);
}
