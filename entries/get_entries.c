/*
** get_entries.c for tekadv in /home/killian/github/tekaventure/entries
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:08:13 2017 Killian
** Last update Wed Sep  6 20:54:48 2017 Killian
*/

#include "tekadv.h"

void	get_entries(t_displayer *displayer)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    move_left(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    move_right(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyDown))
    move_down(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    move_up(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyE))
    interact(displayer);
  if (sfMouse_isButtonPressed(sfMouseLeft))
    shoot(displayer);
  update(displayer);
}
