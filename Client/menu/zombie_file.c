/*
** zombie_file.c for menu tek in /home/ratch7t/Documents/menu_rudy
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Sat Oct  7 12:35:14 2017 ratch7t
** Last update Sun Oct  8 15:27:43 2017 Killian
*/

#include "rudy.h"

int            draw_animation(sfSprite **sprites, t_displayer *displayer)
{
  static int    ptr = 0;

  if (ptr < 0)
    return (1);
  if (sprites[ptr] != NULL)
    sfRenderWindow_drawSprite(displayer->window, sprites[ptr++], NULL);
  else
    ptr = -1;
  return (-1);
}

sfSprite	**play_zombie_norm(sfSprite **sprite_tab)
{
  sfVector2f	pos;
  sfVector2f	scale;

  pos = vector2f(0, 0);
  scale = vector2f(1, 1);
  sprite_tab[15] = init_sprite(ZOMBIE_16, pos, scale);
  sprite_tab[16] = init_sprite(ZOMBIE_17, pos, scale);
  sprite_tab[17] = init_sprite(ZOMBIE_18, pos, scale);
  sprite_tab[18] = init_sprite(ZOMBIE_19, pos, scale);
  sprite_tab[19] = init_sprite(ZOMBIE_20, pos, scale);
  sprite_tab[20] = init_sprite(ZOMBIE_21, pos, scale);
  sprite_tab[21] = init_sprite(ZOMBIE_22, pos, scale);
  sprite_tab[22] = init_sprite(ZOMBIE_23, pos, scale);
  sprite_tab[23] = init_sprite(ZOMBIE_24, pos, scale);
  sprite_tab[24] = init_sprite(ZOMBIE_25, pos, scale);
  sprite_tab[25] = init_sprite(ZOMBIE_26, pos, scale);
  sprite_tab[26] = init_sprite(ZOMBIE_27, pos, scale);
  sprite_tab[27] = init_sprite(ZOMBIE_28, pos, scale);
  sprite_tab[28] = init_sprite(ZOMBIE_29, pos, scale);
  sprite_tab[29] = init_sprite(ZOMBIE_30, pos, scale);
  sprite_tab[30] = init_sprite(ZOMBIE_31, pos, scale);
  sprite_tab[31] = NULL;
  return (sprite_tab);
}

sfSprite	**play_zombie(void)
{
  sfSprite	**sprite_tab;
  sfVector2f	pos;
  sfVector2f	scale;

  pos = vector2f(0, 0);
  scale = vector2f(1, 1);
  if (!(sprite_tab = malloc(sizeof(sfSprite *) * 32)))
    return (NULL);
  sprite_tab[0] = init_sprite(ZOMBIE_1, pos, scale);
  sprite_tab[1] = init_sprite(ZOMBIE_2, pos, scale);
  sprite_tab[2] = init_sprite(ZOMBIE_3, pos, scale);
  sprite_tab[3] = init_sprite(ZOMBIE_4, pos, scale);
  sprite_tab[4] = init_sprite(ZOMBIE_5, pos, scale);
  sprite_tab[5] = init_sprite(ZOMBIE_6, pos, scale);
  sprite_tab[6] = init_sprite(ZOMBIE_7, pos, scale);
  sprite_tab[7] = init_sprite(ZOMBIE_8, pos, scale);
  sprite_tab[8] = init_sprite(ZOMBIE_9, pos, scale);
  sprite_tab[9] = init_sprite(ZOMBIE_10, pos, scale);
  sprite_tab[10] = init_sprite(ZOMBIE_11, pos, scale);
  sprite_tab[11] = init_sprite(ZOMBIE_12, pos, scale);
  sprite_tab[12] = init_sprite(ZOMBIE_13, pos, scale);
  sprite_tab[13] = init_sprite(ZOMBIE_14, pos, scale);
  sprite_tab[14] = init_sprite(ZOMBIE_15, pos, scale);
  sprite_tab = play_zombie_norm(sprite_tab);
  return (sprite_tab);
}
