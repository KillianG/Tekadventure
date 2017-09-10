/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Sun Sep 10 17:09:16 2017 Killian
*/

#include "tekadv.h"

void		draw_game()
{
  t_displayer	*displayer;
  t_player	*distant;
  sfSprite	*sprite;

  sprite = init_sprite(TEST, vector2f(0, 0), vector2f(1, 1));
  displayer = init_displayer();
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      update(displayer);
      send_data(displayer->player);
      printf("local player %.2f\n", displayer->player->hp);
      distant = receive_data();
      displayer->player = update_player(displayer->player);
      get_entries(displayer);      
      sfRenderWindow_drawSprite(displayer->window, displayer->map, NULL);
      draw_weapons(displayer);
      draw_houses(displayer);
      sfRenderWindow_drawSprite(displayer->window, displayer->player->sprite, NULL);
      if (distant != NULL)
	{
	  sfSprite_setPosition(sprite, vector2f((distant->pos.x * -1) + SCREEN_WIDTH/2, (distant->pos.y * -1) + SCREEN_HEIGHT/2));
	  sfRenderWindow_drawSprite(displayer->window, sprite, NULL);
	}
      draw_hand_weapon(displayer);
      continue_shooting(displayer);
      draw_ennemies(displayer);
      draw_zone(displayer);
      draw_arrow(displayer);
      sfRenderWindow_drawText(displayer->window, displayer->hp, NULL);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
}
