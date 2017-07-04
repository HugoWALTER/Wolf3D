/*
** my_draw_line.c for my_drawline.c in /home/walter_h/wireframe/src
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Wed Dec  7 17:54:27 2016 Hugo WALTER
** Last update Sun Jan 15 19:07:28 2017 Hugo WALTER
*/

#include "../include/my.h"

void	my_draw_lineonx(t_my_framebuffer* framebuffer, sfVector2i from,
			sfVector2i to, sfColor color)
{
  float		a;
  int		x;
  int		y;
  sfVector2i	newpos;

  if (from.x > to.x)
    {
      newpos = from;
      from = to;
      to = newpos;
    }
  a = (float)(to.y - from.y) / (to.x - from.x);
  x = from.x;
  while (x != to.x)
    {
      if (from.y == to.y)
	my_put_pixel(framebuffer, x, from.y, sfRed);
      else
	{
	  y = a * (x - from.x) + from.y;
	  my_put_pixel(framebuffer, x, y, sfRed);
	}
      x++;
    }
}

void	my_draw_lineony(t_my_framebuffer* framebuffer, sfVector2i from,
			sfVector2i to, sfColor color)
{
  float		a;
  int		y;
  int		x;
  sfVector2i	newpos;

  if (from.y > to.y)
    {
      newpos = from;
      from = to;
      to = newpos;
    }
  a = (float)(to.y - from.y) / (to.x - from.x);
  y = from.y;
  while (y != to.y)
    {
      if (from.x == to.x)
	my_put_pixel(framebuffer, from.x, y, sfRed);
      else
	{
	  x = a * (y - from.y) + from.x;
	  my_put_pixel(framebuffer, x, y, sfRed);
	}
      y++;
    }
}

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  float		a;
  sfVector2i	newpos;

  a = (float)(to.y - from.y) / (to.x - from.y);
  if (from.x == to.x && from.y == to.y)
    my_put_pixel(framebuffer, from.x, from.y, sfRed);
  if (a >= -1 && a <= 1)
    my_draw_lineonx(framebuffer, from, to, sfRed);
  else
    my_draw_lineony(framebuffer, from, to, sfRed);
}
