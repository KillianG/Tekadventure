/*
** get_entries.c for tekadv in /home/killian/github/tekaventure/entries
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:08:13 2017 Killian
** Last update Thu Oct  5 14:09:01 2017 Killian
*/

#include "tekadv.h"

void	get_entries(t_displayer *displayer)
{
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    move_left(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    move_right(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    move_down(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    move_up(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyE))
    {
      interact_weapon(displayer);
      interact_equipment(displayer);
      interact_ammo(displayer);
    }
  if (sfMouse_isButtonPressed(sfMouseLeft))
    shoot(displayer);
  if (sfKeyboard_isKeyPressed(sfKeyA))
    drop_weapon(displayer);
  update(displayer);
}
