/*
** ammo.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Tue Oct  3 15:03:14 2017 Killian
** Last update Tue Oct  3 15:12:35 2017 Killian
*/

#include "tekadv.h"

void            update_ammo_text(t_displayer *displayer)
{
  sfText_setString(displayer->ammunitions, my_itoa((int)displayer->player->ammos));
}

void            init_ammo_text(t_displayer *displayer)
{
  sfText        *text;
  sfFont        *font;

  font = sfFont_createFromFile(FONT);
  if (!font)
    return ;
  text = sfText_create();
  sfText_setPosition(text, vector2f(30, SCREEN_HEIGHT - 100));
  sfText_setFont(text, font);
  sfText_setColor(text, sfRed);
  sfText_setCharacterSize(text, 50);
  sfText_setString(text, my_itoa((int)displayer->player->ammos));
  displayer->ammunitions = text;
}
