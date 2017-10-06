/*
** collide.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 13:01:29 2017 Killian
** Last update Thu Oct  5 16:11:57 2017 Killian
*/

#include "tekadv.h"

int			is_transparent(t_displayer *displayer)
{
  static sfImage	*image;
  sfColor		color;
  static int		a = 1;
  sfVector2i		pos;

  pos.x = (displayer->player->pos.x * -1) + SCREEN_WIDTH/2;
  pos.y = (displayer->player->pos.y * -1) + SCREEN_HEIGHT/2;
  if (a)
    {
      image = sfTexture_copyToImage(sfSprite_getTexture(displayer->map1));
      a  = !a;
    }
  color = sfImage_getPixel(image, pos.x, pos.y);
  if (color.a == 0)
    return (1);
  return (0);
}

int		collide(t_displayer *displayer)
{
  sfFloatRect	result;
  sfFloatRect	player;
  sfFloatRect	hitbox;
  int		cpt;
  int		collide;

  player = sfSprite_getGlobalBounds(displayer->player->sprite);
  collide = 0;
  cpt = -1;
  if (!is_transparent(displayer))
    return (1);
  while (displayer->houses[++cpt] != NULL && !collide)
    {
      hitbox = sfSprite_getGlobalBounds(displayer->houses[cpt]->sprite);
      if (sfFloatRect_intersects(&player, &hitbox, &result))
	collide = 1;
    }
  cpt = -1;
  while (displayer->ennemies[++cpt] != NULL && !collide)
    {
      hitbox = sfSprite_getGlobalBounds(displayer->ennemies[cpt]->sprite);
      if (sfFloatRect_intersects(&player, &hitbox, &result) &&
	  displayer->ennemies[cpt]->hp > 0)
	{
	  displayer->player->hp -= 0.01;
	  collide = 1;
	}
    }
  return (collide);
}
