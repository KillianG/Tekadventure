/*
** move.c for tekadv in /home/killian/github/tekaventure/Client/mandatory
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 12:04:48 2017 Killian
** Last update Mon Oct  2 14:44:26 2017 Killian
*/

#include "tekadv.h"

int	arrow_pressed()
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) ||
      sfKeyboard_isKeyPressed(sfKeyDown) ||
      sfKeyboard_isKeyPressed(sfKeyLeft) ||
      sfKeyboard_isKeyPressed(sfKeyRight))
    return (1);
  return (0);
}
void			move_player_mouse(t_displayer *displayer)
{
  static sfVector2i	mouse;
  static int		move = 0;

  if (sfMouse_isButtonPressed(sfMouseRight))
    {
      mouse = sfMouse_getPositionRenderWindow(displayer->window);
      mouse.x = (mouse.x + displayer->player->pos.x - SCREEN_WIDTH / 2);
      mouse.y = (mouse.y + displayer->player->pos.y - SCREEN_HEIGHT / 2);
      move = 1;
    }
  if (mouse.x < (int) displayer->player->pos.x * -1 && move)
    move_left(displayer);
  if (mouse.x > (int) displayer->player->pos.x * -1 && move)
    move_right(displayer);
  if (mouse.y < (int) displayer->player->pos.y * -1 && move)
    move_up(displayer);
  if (mouse.y > (int) displayer->player->pos.y * -1 && move)
    move_down(displayer);
  if ((mouse.x == (int) displayer->player->pos.x &&
       mouse.y == (int) displayer->player->pos.y) || arrow_pressed(displayer))
    move = 0;
}
