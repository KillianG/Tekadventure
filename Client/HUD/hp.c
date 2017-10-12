/*
** hp.c for tekadv in /home/killian/github/tekaventure/HUD
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 13:49:44 2017 Killian
** Last update Thu Sep  7 15:59:06 2017 Killian
*/

#include "tekadv.h"

void		update_hp(t_displayer *displayer)
{
  sfText_setString(displayer->hp, my_itoa((int)displayer->player->hp));
}

void		init_hp(t_displayer *displayer)
{
  sfText	*text;
  sfFont	*font;

  font = sfFont_createFromFile(FONT);
  if (!font)
    return ;
  text = sfText_create();
  sfText_setPosition(text, vector2f(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100));
  sfText_setFont(text, font);
  sfText_setColor(text, sfRed);
  sfText_setCharacterSize(text, 50);
  sfText_setString(text, my_itoa((int)displayer->player->hp));
  displayer->hp = text;
}
