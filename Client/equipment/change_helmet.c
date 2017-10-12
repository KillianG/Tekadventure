/*
** change_helmet.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Oct  4 16:54:32 2017 Killian
** Last update Wed Oct  4 17:01:28 2017 Killian
*/

#include "tekadv.h"

void	change_helmet(t_displayer *displayer, int lvl)
{
  if (lvl == 1)
    displayer->player->sprite = init_sprite(PLAYERT1,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
  if (lvl == 2)
    displayer->player->sprite = init_sprite(PLAYERT2,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
  if (lvl == 3)
    displayer->player->sprite = init_sprite(PLAYERT3,
					    vector2f(SCREEN_WIDTH / 2 - 25,
						     SCREEN_HEIGHT / 2 - 25),
					    vector2f(1, 1));
}
