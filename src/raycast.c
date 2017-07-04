/*
** my_raycast.c for WOLF3D DU FUTUR in /home/walter_h/wolf3d
**
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
**
** Started on  Wed Jan  4 11:23:06 2017 Hugo WALTER
** Last update Fri Jan 20 17:20:40 2017 Hugo WALTER
*/

#include "../include/my.h"

sfVector2f	my_move(sfVector2f pos, float direction, float distance)
{
  float	degree;

  degree = M_PI / 180;
  pos.x = pos.x + (distance * cos(direction * (degree)));
  pos.y = pos.y + (distance * sin(direction * (degree)));
  return (pos);
}

float	raycast(sfVector2f pos, float direction,
		int **map, sfVector2i mapSize)
{
  float		rayon;
  float		posxdep;
  float		posydep;

  posxdep = pos.x;
  posydep = pos.y;
  rayon = 0;
  while (map[(int)pos.x][(int)pos.y] == 0 ||
	 mapSize.x > pos.x && mapSize.y > pos.y && pos.x < 0 && pos.y < 0)
    {
      pos = my_move(pos, direction, rayon);
      rayon += 0.00001;
    }
  rayon = sqrtf((powf(pos.x - posxdep, 2) + powf(pos.y - posydep, 2)));
  return (rayon);
}
