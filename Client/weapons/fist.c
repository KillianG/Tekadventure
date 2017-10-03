/*
** fist.c for tekadv in /root/Delivery/tekaventure/Client/weapons
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Oct  2 13:08:21 2017 root
** Last update Tue Oct  3 15:33:05 2017 root
*/

#include "tekadv.h"

void		right_fist(t_displayer *displayer)
{
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->fist->sprite,
			    NULL);
}

void		attack_fist(t_displayer *displayer)
{
  float		angle;

  angle = displayer->player->angle;
  if (displayer->player->weapon != NULL)
    return ;
  if (angle < 45 || angle >= 315)
    right_fist(displayer);
  else if (angle < 135 && angle >= 45)
    printf("DOWN FIST\n");
  else if (angle < 225 && angle >= 135)
    printf("LEFT FIST\n");
  else
    printf("UP FIST\n");
}
