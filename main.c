/*
** main.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:30:23 2017 Killian
** Last update Sun Sep 10 13:22:36 2017 Killian
*/

#include "tekadv.h"

int	main(int ac, char **av)
{
  if (ac == 3)
    init_connection(av[1], av[2]);
  menu();
  return (0);
}
