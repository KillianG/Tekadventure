/*
** ennemies.c for tekadv in /home/killian/github/tekaventure/ennemy
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:17:11 2017 Killian
** Last update Thu Sep  7 14:42:23 2017 Killian
*/

#include "tekadv.h"

void	init_ennemies(t_displayer *displayer)
{
  displayer->ennemies[0] = init_ennemy(vector2f(300, 600));
  displayer->ennemies[1] = init_ennemy(vector2f(150, 600));
  displayer->ennemies[NB_ENNEMY] = NULL;
}
