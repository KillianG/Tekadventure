/*
** vector.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Tue Sep  5 10:40:20 2017 ratch7t
** Last update Tue Sep  5 10:41:19 2017 ratch7t
*/

#include "rudy.h"

sfVector2f	vector2f(float x, float y)
{
  sfVector2f	v;

  v.x = x;
  v.y = y;
  return (v);
}
