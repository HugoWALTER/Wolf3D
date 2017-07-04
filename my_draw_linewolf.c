/*
** my_draw_linewolf.c for my_draw_linewolf in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 19:16:09 2017 Hugo WALTER
** Last update Sun Jan 15 19:16:12 2017 Hugo WALTER
*/

#include "../include/my.h"

void	my_draw_y(t_my_drawl *dl, t_my_framebuffer *framebuffer, sfColor color)
{
  dl->j = dl->dy / 2;
  while (dl->i <= dl->dy)
    {
      dl->y += dl->ly;
      dl->j += dl->dx;
      if (dl->j >= dl->dy)
	{
	  dl->j -= dl->dy;
	  dl->x += dl->lx;
	}
      my_put_pixel(framebuffer, dl->x, dl->y, color);
      dl->i++;
    }
}

void	my_draw_x(t_my_drawl *dl, t_my_framebuffer *framebuffer, sfColor color)
{
  dl->j = dl->dx / 2;
  while (dl->i <= dl->dx)
    {
      dl->x += dl->lx;
      dl->j += dl->dy;
      if (dl->j >= dl->dx)
	{
	  dl->j -= dl->dx;
	  dl->y += dl->ly;
	}
      dl->i++;
      my_put_pixel(framebuffer, dl->x, dl->y, color);
    }
}

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  t_my_drawl	*dl;

  dl = malloc(sizeof(*dl));
  dl->i = 1;
  dl->x = from.x;
  dl->y = from.y;
  dl->dx = to.x - from.x;
  dl->dy = to.y - from.y;
  dl->lx = (dl->dx > 0) ? 1 : -1;
  dl->ly = (dl->dy > 0) ? 1 : -1;
  dl->dx = my_abs(dl->dx);
  dl->dy = my_abs(dl->dy);
  my_put_pixel(framebuffer, dl->x, dl->y, color);
  ((dl->dx > dl->dy) ? (my_draw_x(dl, framebuffer, color)) :
   (my_draw_y(dl, framebuffer, color)));
}
