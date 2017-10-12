/*
** init_house.c for tekadv in /home/killian/github/tekaventure/house
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Aug 31 13:26:15 2017 Killian
** Last update Wed Sep  6 15:13:28 2017 Killian
*/

#include "tekadv.h"

t_house		*init_house(sfVector2f pos, t_displayer *displayer)
{
  t_house	*house;
  sfSprite	*sprite;

  house = malloc(sizeof(t_house));
  if (house == NULL)
    return (NULL);
  house->start = pos;
  pos.x += displayer->player->pos.x;
  pos.y += displayer->player->pos.y;
  sprite = init_sprite(HOUSE, pos, vector2f(1, 1));
  house->sprite = sprite;
  house->hitbox = sfSprite_getTextureRect(sprite);
  house->pos = pos;
  return (house);
}
