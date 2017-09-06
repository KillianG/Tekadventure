/*
** shoot.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:43:14 2017 Killian
** Last update Wed Sep  6 21:18:53 2017 Killian
*/

#include "tekadv.h"

int     is_outofbound(sfVector2f pos)
{
  if (pos.x > SCREEN_WIDTH || pos.x < 0)
    return (1);
  if (pos.y > SCREEN_HEIGHT || pos.y < 0)
    return (1);
  return (0);
}

void		shoot(t_displayer *displayer)
{
  if (!displayer->player->shoot && displayer->player->has_weapon)
    {
      displayer->player->shoot = 1;
      sfSprite_setRotation(displayer->bullet, get_angle_from_mouse(displayer));
      displayer->player->shooting_angle = get_angle_from_mouse(displayer);
      sfSprite_setPosition(displayer->bullet,
			   vector2f(SCREEN_WIDTH/2 + 5,
				    SCREEN_HEIGHT/2 + 20));
    }
}

void			continue_shooting(t_displayer *displayer)
{
  if (!displayer->player->shoot)
    return ;
  sfSprite_setPosition(displayer->bullet,
		       move_forward(sfSprite_getPosition(displayer->bullet),
				    displayer->player->shooting_angle, 0.8));
  if (is_outofbound(sfSprite_getPosition(displayer->bullet)))
        displayer->player->shoot = 0;
  sfRenderWindow_drawSprite(displayer->window, displayer->bullet, NULL);
}
