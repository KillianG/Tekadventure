/*
** zombie_file.c for menu tek in /home/ratch7t/Documents/menu_rudy
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Sat Oct  7 12:35:14 2017 ratch7t
** Last update Sat Oct  7 14:00:07 2017 ratch7t
*/

#include "rudy.h"

void		init_zombie_start(t_sprite *sprit)
{
  sprit->zomb_01 = init_sprite_menu(ZOMBIE_1);
  sprit->zomb_02 = init_sprite_menu(ZOMBIE_2);
  sprit->zomb_03 = init_sprite_menu(ZOMBIE_3);
  sprit->zomb_04 = init_sprite_menu(ZOMBIE_4);
  sprit->zomb_05 = init_sprite_menu(ZOMBIE_5);
  sprit->zomb_06 = init_sprite_menu(ZOMBIE_6);
  sprit->zomb_07 = init_sprite_menu(ZOMBIE_7);
  sprit->zomb_08 = init_sprite_menu(ZOMBIE_8);
  sprit->zomb_09 = init_sprite_menu(ZOMBIE_9);
  sprit->zomb_10 = init_sprite_menu(ZOMBIE_10);
  sprit->zomb_11 = init_sprite_menu(ZOMBIE_11);
  sprit->zomb_12 = init_sprite_menu(ZOMBIE_12);
  sprit->zomb_13 = init_sprite_menu(ZOMBIE_13);
  sprit->zomb_14 = init_sprite_menu(ZOMBIE_14);
  sprit->zomb_15 = init_sprite_menu(ZOMBIE_15);
  init_zombie_end(sprit);
}
void		init_zombie_end(t_sprite *sprit)
{
  sprit->zomb_16 = init_sprite_menu(ZOMBIE_16);
  sprit->zomb_17 = init_sprite_menu(ZOMBIE_17);
  sprit->zomb_18 = init_sprite_menu(ZOMBIE_18);
  sprit->zomb_19 = init_sprite_menu(ZOMBIE_19);
  sprit->zomb_20 = init_sprite_menu(ZOMBIE_20);
  sprit->zomb_21 = init_sprite_menu(ZOMBIE_21);
  sprit->zomb_22 = init_sprite_menu(ZOMBIE_22);
  sprit->zomb_23 = init_sprite_menu(ZOMBIE_23);
  sprit->zomb_24 = init_sprite_menu(ZOMBIE_24);
  sprit->zomb_25 = init_sprite_menu(ZOMBIE_25);
  sprit->zomb_26 = init_sprite_menu(ZOMBIE_26);
  sprit->zomb_27 = init_sprite_menu(ZOMBIE_27);
  sprit->zomb_28 = init_sprite_menu(ZOMBIE_28);
  sprit->zomb_29 = init_sprite_menu(ZOMBIE_29);
  sprit->zomb_30 = init_sprite_menu(ZOMBIE_30);
  sprit->zomb_31 = init_sprite_menu(ZOMBIE_31);
}

int		play_zombie(t_displayer *displayer, t_sprite *sprit)
{
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_02, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_03, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_04, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_05, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_06, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_07, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_08, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_09, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_10, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_11, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_12, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_13, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_14, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_15, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_16, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_17, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_18, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_19, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_20, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_21, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_22, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_23, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_24, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_25, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_26, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_27, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_28, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_29, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_30, NULL);
  usleep(1000000);
  sfRenderWindow_drawSprite(displayer->window, sprit->zomb_31, NULL);
  usleep(1000000);
  return (0);
}
