/*
** shoot.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:43:14 2017 Killian
** Last update Thu Oct  5 11:55:11 2017 Killian
*/

#include "tekadv.h"

sfVector2f	center(sfVector2f pos, t_displayer *displayer)
{
  sfVector2f	result;

  result.x = (pos.x * -1) + SCREEN_WIDTH / 2 + displayer->player->pos.x;
  result.y = (pos.y * -1) + SCREEN_HEIGHT / 2 + displayer->player->pos.y;
  return (result);
}

void		check_hit(t_displayer *displayer)
{
  sfFloatRect	bullet;
  sfFloatRect	hitbox;
  sfFloatRect	result;
  int		cpt;
  int		collide;
  sfSprite	*sprite;

  collide = 0;
  cpt = -1;
  bullet = sfSprite_getGlobalBounds(displayer->bullet);
  while (++cpt != 10 && !collide)
    {
      if (displayer->players[cpt] != NULL)
	{
	  sprite = init_sprite(TEST, center(displayer->players[cpt]->pos, displayer),
			       vector2f(1, 1));
	  hitbox = sfSprite_getGlobalBounds(sprite);
	  if (sfFloatRect_intersects(&bullet, &hitbox, &result) &&
	      displayer->players[cpt]->health > 0)
	    {
	      displayer->player->shoot = 0;
	      attack(displayer->player->weapon->damages, cpt);
	      if (displayer->players[cpt]->health <= 0)
		displayer->players[cpt] = NULL;
	      collide = 1;
	    }
	}
    }
}

int	is_outofbound(sfVector2f pos)
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
      if (displayer->player->ammos > 0)
	{
	  displayer->player->ammos -= 1;
	  displayer->player->shoot = 1;
	  sfSprite_setRotation(displayer->bullet,
			       get_angle_from_mouse(displayer));
	  displayer->player->shooting_angle = get_angle_from_mouse(displayer);
	  sfSprite_setPosition(displayer->bullet,
			       vector2f(SCREEN_WIDTH/2 + 5,
					SCREEN_HEIGHT/2 + 20));
	}
    }
  else if (!displayer->player->shoot)
    {
      attack_fist(displayer);
      check_fist_hit(displayer);
      sfSleep(sfMilliseconds(100));
    }
}

void	continue_shooting(t_displayer *displayer)
{
  if (!displayer->player->shoot)
    return ;
  sfSprite_setPosition(displayer->bullet,
		       move_forward(sfSprite_getPosition(displayer->bullet),
				    displayer->player->shooting_angle, 3));
  if (is_outofbound(sfSprite_getPosition(displayer->bullet)))
        displayer->player->shoot = 0;
  check_hit(displayer);
  sfRenderWindow_drawSprite(displayer->window, displayer->bullet, NULL);
}
