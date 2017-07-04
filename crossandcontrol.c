/*
** crossandcontrol.c for crossandcontrols in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 18:50:31 2017 Hugo WALTER
** Last update Mon Jan 16 18:08:16 2017 Hugo WALTER
*/

#include "my.h"

sfVector2f	controls_updown(sfVector2f pos, float direction, t_mapsize *ms)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    pos = move_up(pos, direction, ms);
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    pos = move_down(pos, direction, ms);
  return (pos);
}

float	controls_rightleft(sfVector2f pos, float direction, t_mapsize *ms)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    direction = move_right(pos, direction, ms);
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    direction = move_left(pos, direction, ms);
  return (direction);
}

sfVector2i	take2D(int a, int b)
{
  sfVector2i	cross;

  cross.x = a;
  cross.y = b;
  return (cross);
}

void	draw_crosshair(t_mapsize *ms)
{
  my_draw_line(ms->structure, take2D(300, 240), take2D(310, 240), sfBlack);
  my_draw_line(ms->structure, take2D(320, 240), take2D(330, 240), sfBlack);
  my_draw_line(ms->structure, take2D(315, 225), take2D(315, 235), sfBlack);
  my_draw_line(ms->structure, take2D(315, 245), take2D(315, 255), sfBlack);
}
