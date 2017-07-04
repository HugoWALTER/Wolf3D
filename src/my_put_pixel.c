/*
** my_put_pixel.c for my_put_pixel in /home/walter_h/wireframe/src
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Wed Dec  7 17:53:04 2016 Hugo WALTER
** Last update Mon Dec 12 09:28:37 2016 Hugo WALTER
*/

#include "../include/my.h"

void    my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color)
{
  if (x < framebuffer->width && y < framebuffer->height && x > 0 && y > 0)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
