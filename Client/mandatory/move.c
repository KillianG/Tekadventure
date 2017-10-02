/*
** move.c for tekadv in /home/killian/github/tekaventure/Client/mandatory
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Oct  2 12:04:48 2017 Killian
** Last update Mon Oct  2 12:41:15 2017 Killian
*/

#include "tekadv.h"

void			move_player_mouse(t_displayer *displayer)
{
  static sfVector2i	mouse;
  static int		move = 0;

  if (sfMouse_isButtonPressed(sfMouseRight))
    {
      mouse = sfMouse_getPositionRenderWindow(displayer->window);
      mouse.x = (mouse.x + displayer->player->pos.x + SCREEN_WIDTH / 2) * -1;
      mouse.y = (mouse.y + displayer->player->pos.y + SCREEN_HEIGHT / 2) * -1;
      move = 1;
    }
  printf("%d && %d\n", mouse.x, (int) displayer->player->pos.x);
  if (mouse.x < (int) displayer->player->pos.x && move)
    move_left(displayer);
  if (mouse.x > (int) displayer->player->pos.x && move)
    move_right(displayer);
  if (mouse.y < (int) displayer->player->pos.y && move)
    move_up(displayer);
  if (mouse.y > (int) displayer->player->pos.y && move)
    move_down(displayer);
  if (mouse.x == (int) displayer->player->pos.x && mouse.y == (int) displayer->player->pos.y)
    move = 0;
}
