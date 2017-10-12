/*
** get_entries.c for tekadv in /home/killian/github/tekaventure/entries
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 18:08:13 2017 Killian
** Last update Sun Oct  8 14:33:43 2017 Killian
*/

#include "tekadv.h"

void	get_entries(t_displayer *displayer)
{
  if (sfKeyboard_isKeyPressed(displayer->config->left))
    move_left(displayer);
  if (sfKeyboard_isKeyPressed(displayer->config->right))
    move_right(displayer);
  if (sfKeyboard_isKeyPressed(displayer->config->down))
    move_down(displayer);
  if (sfKeyboard_isKeyPressed(displayer->config->up))
    move_up(displayer);
  if (sfKeyboard_isKeyPressed(displayer->config->take))
    {
      interact_weapon(displayer);
      interact_equipment(displayer);
      interact_ammo(displayer);
    }
  if (sfMouse_isButtonPressed(sfMouseLeft))
    shoot(displayer);
  if (sfMouse_isButtonPressed(sfMouseRight))
    move_player_mouse(displayer);
  if (sfKeyboard_isKeyPressed(displayer->config->drop))
    drop_weapon(displayer);
  update(displayer);
}
