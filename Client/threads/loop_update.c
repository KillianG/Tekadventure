/*
** loop_update.c for tekadv in /home/killian/github/tekaventure/threads
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep 20 13:01:22 2017 Killian
** Last update Mon Oct  2 16:12:35 2017 Killian
*/

#include "tekadv.h"

void	loop_update(void *param)
{
  t_displayer	*displayer;

  displayer = param;
  while (1)
    update(displayer);
}
