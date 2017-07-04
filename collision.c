/*
** collision.c for collision in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 17:37:07 2017 Hugo WALTER
** Last update Sun Jan 15 19:22:57 2017 Hugo WALTER
*/

#include "my.h"

sfVector2f	move_coll(sfVector2f pos, float direction,
			  float distance, t_mapsize *ms)
{
  float	degree;

  degree = M_PI / 180;
  if (ms->map[(int)(pos.x + (distance * cos(direction * (degree))))]
      [(int)pos.y] == 0)
    pos.x = pos.x + (distance * cos(direction * (degree)));
  if (ms->map[(int)pos.x]
      [(int)(pos.y + (distance * sin(direction * (degree))))] == 0)
    pos.y = pos.y + (distance * sin(direction * (degree)));
  return (pos);
}
