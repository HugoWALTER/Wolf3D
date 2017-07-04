/*
** move.c for move in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 18:39:45 2017 Hugo WALTER
** Last update Sun Jan 15 18:44:11 2017 Hugo WALTER
*/

#include "my.h"

sfVector2f	move_up(sfVector2f pos, float direction, t_mapsize *ms)
{
  pos = move_coll(pos, direction + 30, 0.15, ms);
  ms->savepos.x = pos.x;
  ms->savepos.y = pos.y;
  disp_wall(pos, direction, ms->map, ms);
  return (pos);
}

sfVector2f	move_down(sfVector2f pos, float direction, t_mapsize *ms)
{
  pos = move_coll(pos, direction - 150, 0.15, ms);
  ms->savepos.x = pos.x;
  ms->savepos.y = pos.y;
  disp_wall(pos, direction, ms->map, ms);
  return (pos);
}

float	move_right(sfVector2f pos, float direction, t_mapsize *ms)
{
  direction = direction + 3;
  if (direction < 0.0)
    direction += 360.0;
  else
    if (direction > 360.0)
      direction -= 360.0;
  disp_wall(pos, direction, ms->map, ms);
  return (direction);
}

float	move_left(sfVector2f pos, float direction, t_mapsize *ms)
{
  direction = direction - 3;
  if (direction < 0.0)
    direction += 360.0;
  else
    if (direction > 360.0)
      direction -= 360.0;
  disp_wall(pos, direction, ms->map, ms);
  return (direction);
}
