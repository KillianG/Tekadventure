/*
** init_fist.c for tekadv in /root/Delivery/tekaventure/Client/fist
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Oct  3 06:06:48 2017 root
** Last update Wed Oct  4 12:00:44 2017 root
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

void		check_fist_hit(t_displayer *displayer)
{
  sfFloatRect	fist;
  sfFloatRect	hitbox;
  sfFloatRect	result;
  int		cpt;
  int		collide;

  collide = 0;
  cpt = -1;
  fist = sfSprite_getGlobalBounds(displayer->player->fist->sprite);
  while (displayer->ennemies[++cpt] != NULL && !collide)
    {
      hitbox = sfSprite_getGlobalBounds(displayer->ennemies[cpt]->sprite);
      if (sfFloatRect_intersects(&fist, &hitbox, &result) &&
	  displayer->ennemies[cpt]->hp > 0)
	{
	  displayer->player->shoot = 0;
	  displayer->ennemies[cpt]->hp -= displayer->player->fist->damages;
	  collide = 1;
	}
    }
}
