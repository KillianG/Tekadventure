/*
** loop_update.c for tekadv in /home/killian/github/tekaventure/threads
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep 20 13:01:22 2017 Killian
** Last update Sat Sep 23 17:14:04 2017 Killian
*/

#include "tekadv.h"

void	*loop_update(t_displayer *displayer)
{
  while (1)
    update(displayer);
}
