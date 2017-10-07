/*
** init_sprite.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:03:42 2017 Killian
** Last update Sat Oct  7 18:27:50 2017 Killian
*/

#include "tekadv.h"

sfSprite	*init_sprite(char *path, sfVector2f pos, sfVector2f scale)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfTexture_setRepeated(texture, sfFalse);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, pos);
  sfSprite_setScale(sprite, scale);
  return (sprite);
}
