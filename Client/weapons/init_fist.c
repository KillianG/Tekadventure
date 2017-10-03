/*
** init_fist.c for tekadv in /root/Delivery/tekaventure/Client/fist
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Oct  3 06:06:48 2017 root
** Last update Tue Oct  3 17:40:41 2017 root
*/

#include "tekadv.h"

void		init_fist(t_displayer *displayer)
{
  t_fist	*fist;

  fist = malloc(sizeof(t_fist));
  if (fist == NULL)
    return ;
  fist->pos = vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
  fist->sprite = init_sprite(FIST, fist->pos,
			     vector2f(0.01, 0.01));
  fist->damages = 1;
  displayer->player->fist = fist;
}
