/*
** music.c for tekadv in /home/killian/github/tekaventure
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Sun Oct  8 18:00:19 2017 Killian
** Last update Sun Oct  8 18:37:30 2017 Killian
*/

#include "tekadv.h"

sfMusic		*create_music(char *path)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(path);
  return (music);
}

void		start_music()
{
  sfMusic	*music;

  music = create_music(MUSIC);
  sfMusic_setVolume(music, 50);
  sfMusic_play(music);
}

void		start_shoot()
{
  sfMusic	*shoot;

  shoot = create_music(SHOOT);
  sfMusic_setLoop(shoot, sfFalse);
  sfMusic_play(shoot);
}
